#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--)
    {
        long long ans=0,n;
        cin>>n;
        long long a[100005],b[100005],c[100005],a1[100005],b1[100005],c1[100005];
        for(long long i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            a1[i]=a[i];
            b1[i]=b[i];
            c1[i]=c[i];
        }
        sort(a1+1,a1+1+n,cmp);
        sort(b1+1,b1+1+n,cmp);
        sort(c1+1,c1+1+n,cmp);
        for(long long i=1;i<=n;i++)
        {
            long long m=0;
            bool o=1;
            for(long long j=1;j<=n/2;j++)
            {
                if(a[i]==a1[j])
                {
                    a1[j]=0;
                    m=max(a[i],m);
                    break;
                }
            }
            for(long long j=1;j<=n/2;j++)
            {
                if(b[i]==b1[j])
                {
                    b1[j]=0;
                    m=max(b[i],m);
                    break;
                }
            }
            for(long long j=1;j<=n/2;j++)
            {
                if(c[i]==c1[j])
                {
                    c1[j]=0;
                    m=max(c[i],m);
                    break;
                }
            }
            ans+=m;
        }
        cout<<ans<<endl;
    }
    return 0;
}
