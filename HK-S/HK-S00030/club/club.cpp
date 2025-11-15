#include<bits/stdc++.h>
using namespace std;

const long long N=1e6;

long long t,a[N],b[N],c[N];

long long a1,a2,a3,a4,a5,a6;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        a1=a[1]+b[2];
        a2=a[1]+c[2];
        a3=b[1]+a[2];
        a4=b[1]+c[2];
        a5=c[1]+a[2];
        a6=c[1]+b[2];
        int tt;
        tt=max(a1,max(a2,max(a3,max(a4,max(a5,a6)))));
        cout<<tt;
    }
    return 0;
}
