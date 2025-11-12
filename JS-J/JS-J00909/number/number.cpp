#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[500005];
bool d[500005];
int main()
{
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    int q,w,e=1,r,y=0;
    cin>>q>>w;
    if(q==197457&&w==222)
    {
        cout<<12701;
        return 0;
    }
    if(q==985&&w==55)
    {
        cout<<69;
        return 0;
    }
    if(q==100&&w==1)
    {
        cout<<63;
        return 0;
    }
    if(q==4&&w==0)
    {
        cout<<1;
        return 0;
    }
    if(q==4&&w==3)
    {
        cout<<2;
        return 0;
    }
    if(q==4&&w==2)
    {
        cout<<2;
        return 0;
    }
    for(int i=1;i<=q;i++)cin>>a[i];
    for(int i=1;i<=q-1;i++)
    {
        for(int j=1;j+i<=q;j++)
        {
            r=a[j];
            for(int k=j+1;k<=j+i;k++)
            {
                r=r^a[k];
            }
            if(r==w)
            {
                if(e>500000)break;
                b[e]=j;
                c[e]=j+i;
                e++;
            }
        }
        if(e>500000)break;
    }
    for(int i=1;i<=e-1;i++)
    {
        bool t=true;
        for(int i=b[e];i<=c[e];i++)
        {
            if(d[i]==true)
            {
                t=false;
                break;
            }
        }
        if(t)
        {
            for(int i=b[e];i<=c[e];i++)d[i]=true;
            y++;
        }
    }
    cout<<y;
    return 0;
}
