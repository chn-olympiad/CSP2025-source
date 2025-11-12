#include<bits/stdc++.h>
using namespace std;
long long n[10005],t,a[10005],b[10005],c[10005],d,aa,bb,cc;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>t;
    for(long long i=1;i<=t;i++)
    {
        cin>>n[i];
        for(long long j=1;j<=n[i];j++)
        {
            cin>>a[j];
            cin>>b[j];
            cin>>c[j];
            d=d+max(max(a[j],b[j]),c[j]);
            for(long long x=1;x<=n[i];x++)
            {
                if(max(max(a[j],b[j]),c[j])==a[i])
                {
                    aa++;
                }
                if(max(max(a[j],b[j]),c[j])==b[i])
                {
                    bb++;
                }
                if(max(max(a[j],b[j]),c[j])==c[i])
                {
                    cc++;
                }
            }
            while(aa>n[i]/2)
            {
                d=d-a[j]+max(b[j],c[j]);
                aa--;
            }
            while(bb>n[i]/2)
            {
                d=d-b[j]+max(a[j],c[j]);
                bb--;
            }
            while(cc>n[i]/2)
            {
                d=d-c[j]+max(b[j],a[j]);
                cc--;
            }
            if(j==n[i])
            {
                cout<<d<<endl;
                d=0;
            }
        }

    }
    return 0;
}
