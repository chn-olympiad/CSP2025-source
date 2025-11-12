#include <sdk.h> // Code::Blocks SDK
#include <configurationpanel.h>
#include "road_cpp.h"

// Register the plugin with Code::Blocks.
// We are using an anonymous namespace so we don't litter the global one.
namespace
{
    PluginRegistrant<road_cpp> reg(_T("road_cpp"));
}

// constructor
road_cpp::road_cpp()
{
    // Make sure our resources are available.
    // In the generated boilerplate code we have no resources but when
    // we add some, it will be nice that this code is in place already ;)
    if(!Manager::LoadResource(_T("road_cpp.zip")))
    {
        NotifyMissingFile(_T("road_cpp.zip"));
    }
}

// destructor
road_cpp::~road_cpp()
{
}

void road_cpp::OnAttach()
{
    // do whatever initialization you need for your plugin
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be TRUE...
    // You should check for it in other functions, because if it
    // is FALSE, it means that the application did *not* "load"
    // (see: does not need) this plugin...
}

void road_cpp::OnRelease(bool appShutDown)
{
    // do de-initialization for your plugin
    // if appShutDown is true, the plugin is unloaded because Code::Blocks is being shut down,
    // which means you must not use any of the SDK Managers
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be FALSE...
}

int road_cpp::Execute()
{
    // do your magic ;)
    NotImplemented(_T("road_cpp::Execute()"));
    return -1;
}
