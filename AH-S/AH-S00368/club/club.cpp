#include<bits/stdc++.h>
using namespace std;
int T;
int n;
long long a1[100005],a2[100005],a3[100005];
long long b1[100005],b2[100005],b3[100005];
int b1n,b2n,b3n;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        b1n=b2n=b3n=0;
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a1[i]>>a2[i]>>a3[i];
            if(a1[i]>a2[i] && a1[i]>a3[i])
            {
                b1[++b1n]=min(a1[i]-a2[i],a1[i]-a3[i]);
                ans+=a1[i];
            }
            else if(a2[i]>a3[i])
            {
                b2[++b2n]=min(a2[i]-a1[i],a2[i]-a3[i]);
                ans+=a2[i];
            }
            else
            {
                b3[++b3n]=min(a3[i]-a1[i],a3[i]-a2[i]);
                ans+=a3[i];
            }
        }
        sort(b1+1,b1+b1n+1);
        sort(b2+1,b2+b2n+1);
        sort(b3+1,b3+b3n+1);
        if(b1n>n/2)
        {
            for(int i=1;i<=b1n-n/2;i++)
                ans-=b1[i];
        }
        if(b2n>n/2)
        {
            for(int i=1;i<=b2n-n/2;i++)
                ans-=b2[i];
        }
        if(b3n>n/2)
        {
            for(int i=1;i<=b3n-n/2;i++)
                ans-=b3[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
