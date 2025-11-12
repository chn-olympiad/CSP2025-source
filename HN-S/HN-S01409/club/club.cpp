#include <bits/stdc++.h>
using namespace std;
struct cs{
    int a1,a2,a3;
    int z;
};
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int n,c1=0,c2=0,c3=0,ma=20001,mb=20001,mc=20001,mai=0,mbi=0,mci=0,x=0;
        cin>>n;
        cs c[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>c[i].a1>>c[i].a2>>c[i].a3;
            if(c[i].a1>c[i].a2&&c[i].a1>c[i].a3)c[i].z=1;
            if(c[i].a2>c[i].a1&&c[i].a2>c[i].a3)c[i].z=2;
            if(c[i].a3>c[i].a2&&c[i].a3>c[i].a1)c[i].z=3;
        }

        for(int i=1;i<=n;i++)
        {
            if(c[i].z==1)
            {
                if(c1<n/2){
                    x+=c[i].a1;
                    c1++;
                    if(c[i].a1<ma)
                    {
                        ma=c[i].a1;
                        mai=i;
                    }
                }
                else if(c[i].a1>c[mai].a1){
                    x-=c[mai].a1;
                    int minn=1000000,mini;
                    for(int j=1;j<=i;j++)
                    {
                        if(c[j].z!=1)continue;
                        if(c[j].a1<minn)
                        {
                            minn=c[j].a1;
                            mini=j;
                        }
                    }
                    if(c[mai].a3>c[mai].a2)x+=c[mai].a3;
                    else {
                        x+=c[mai].a2;
                    }
                    mai=mini;
                    ma=minn;
                    x+=c[i].a1;
                }
                else{
                    if(c[i].a3>c[i].a2)x+=c[i].a3;
                    else {
                        x+=c[i].a2;
                    }
                }
            }
            if(c[i].z==2)
            {
                if(c2<n/2){
                    x+=c[i].a2;
                    c2++;
                    if(c[i].a2<mb)
                    {
                        mb=c[i].a2;
                        mbi=i;
                    }
                }
                else if(c[i].a2>c[mbi].a2){
                    x-=c[mbi].a2;
                    int minn=1000000,mini;
                    for(int j=1;j<=i;j++)
                    {
                        if(c[j].z!=2)continue;
                        if(c[j].a2<minn)
                        {
                            minn=c[j].a2;
                            mini=j;
                        }
                    }
                    if(c[mbi].a3>c[mbi].a1)x+=c[mbi].a3;
                    else {
                        x+=c[mbi].a1;
                    }
                    mbi=mini;
                    mb=minn;
                    x+=c[i].a2;
                }
                else{
                    if(c[i].a3>c[i].a1)x+=c[i].a3;
                    else {
                        x+=c[i].a1;
                    }
                }
            }
            if(c[i].z==3)
            {
                if(c3<n/2){
                    x+=c[i].a3;
                    c3++;
                    if(c[i].a3<mc)
                    {
                        mc=c[i].a3;
                        mci=i;
                    }
                }
                else if(c[i].a3>c[mci].a3){
                    x-=c[mci].a3;
                    int minn=1000000,mini;
                    for(int j=1;j<=i;j++)
                    {
                        if(c[j].z!=3)continue;
                        if(c[j].a3<minn)
                        {
                            minn=c[j].a3;
                            mini=j;
                        }
                    }
                    if(c[mci].a1>c[mci].a2)x+=c[mci].a1;
                    else {
                        x+=c[mci].a2;
                    }
                    mai=mini;
                    ma=minn;
                    x+=c[i].a3;
                }
                else{
                    if(c[i].a1>c[i].a2)x+=c[i].a1;
                    else {
                        x+=c[i].a2;
                    }
                }
            }
        }
        cout<<x<<endl;
    }
    return 0;
}
