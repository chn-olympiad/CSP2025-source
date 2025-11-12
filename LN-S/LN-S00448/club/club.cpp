#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int k;
int n;
int a[10001];
int b[10001];
int c[10001];
int e,f,g,h,m,v;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j]>>b[j]>>c[j];
        }
        if(n==2)
        {
            e=0;
            f=0;
            g=0;
            h=0;
            m=0;
            v=0;
            e=a[1]+b[2];
            f=a[1]+c[2];
            g=b[1]+a[2];
            h=b[1]+c[2];
            m=c[1]+a[2];
            v=c[1]+b[2];
            int ans=-1;
            ans=max(ans,e);
            ans=max(ans,f);
            ans=max(ans,g);
            ans=max(ans,h);
            ans=max(ans,m);
            ans=max(ans,v);
            cout<<ans<<endl;
        }

    }
    return 0;
}
