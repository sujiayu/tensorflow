/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_LITE_DELEGATES_GPU_METAL_KERNELS_CONV_H_
#define TENSORFLOW_LITE_DELEGATES_GPU_METAL_KERNELS_CONV_H_

#include <vector>

#include "tensorflow/lite/delegates/gpu/common/gpu_info.h"
#include "tensorflow/lite/delegates/gpu/common/model.h"
#include "tensorflow/lite/delegates/gpu/common/operations.h"
#include "tensorflow/lite/delegates/gpu/metal/compute_task_descriptor.h"
#include "tensorflow/lite/delegates/gpu/metal/runtime_options.h"

namespace tflite {
namespace gpu {
namespace metal {

ComputeTaskDescriptor ConvolutionGeneric(ValueId input_id, ValueId output_id,
                                         const BHWC& dst_shape,
                                         const Convolution2DAttributes& attr,
                                         const GpuInfo& gpu_info,
                                         const RuntimeOptions& options);

ComputeTaskDescriptor ConvolutionWino4x4To6x6(
    ValueId input_id, ValueId output_id, const BHWC& dst_shape,
    const Convolution2DAttributes& attr, const GpuInfo& gpu_info,
    const RuntimeOptions& options);

}  // namespace metal
}  // namespace gpu
}  // namespace tflite

#endif  // TENSORFLOW_LITE_DELEGATES_GPU_METAL_KERNELS_CONV_H_
