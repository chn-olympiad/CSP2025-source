#include<bits/stdc++.h>
using namespace std;
int n,tail=2;
int a[5005];
long long ans=0;
const int N=998244353;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==3)
    {
        int Max=-1,sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=a[i];
            Max=max(Max,a[i]);
        }
        if(sum>Max*2) cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }
    for(int i=3;i<=n;i++)
    {
        long long fen=1,fenm=1;
        for(int j=n;j>=1;j--) fen=(fen*j)%N;
        for(int j=i;j>=1;j--) fenm=(fenm*j)%N;
        for(int j=(n-i);j>=1;j--) fenm=(fenm*j)%N;
        ans=ans%N+((fen/fenm)%N);
    }
    cout<<ans<<endl;
    return 0;
}
