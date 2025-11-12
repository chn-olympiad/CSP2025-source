#include<bits/stdc++.h>
using namespace std;
int m,n,k,zx=0,js;
int cs1[1000005];
int cs2[1000005];
int xlq[100000005];
int csh[100000005];
int clc[100000005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>cs1[i]>>cs2[i]>>xlq[i];
    }
    for(int i=1;i<=k;i++)
    {
        cin>>csh[i];
        for(int j=1;j<=n;j++)
        {
            cin>>clc[i];
        }
    }
    for(int i=0;i<=m;i++)
    {
        for(int j=1;i<=m;i++)
        {
            for(int d=2;d<=m;d++)
            {
                if(cs1[i]+cs2[i]+cs1[j]+cs2[j]+cs1[d]+cs2[d]==15)
                {
                    if(zx<xlq[i]+xlq[j]+xlq[d])
                    zx=zx<xlq[i]+xlq[j]+xlq[d];
                }
            }
        }
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            js=js+clc[i];
        }
        if(js<zx)
        {
            zx=js;
        }
        js=0;
    }
    for(int i=1;i<=k;i++)
    {
         for(int j=1;j<=n;j++)
        {
            js=js+clc[i];
                for(int d=0;d<=m;d++)
                {
                    if(j<cs1[d]&&j<cs2[d])
                    {
                        if(xlq[d]+clc[cs1[d]]<clc[cs1[d]]+clc[cs2[d]]||xlq[d]+clc[cs2[d]]<clc[cs1[d]]+clc[cs2[d]])
                        {
                            js=js+xlq[d];
                        }
                        if(js<zx)
                        {
                            zx=js;
                        }
                    }
                }
        }
    }
    cout<<zx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
