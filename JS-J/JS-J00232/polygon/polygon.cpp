#include<bits/stdc++.h>
#define p 998244353
using namespace std;
int n,x[5010],ans;
bool b[5010];
bool check()
{
    int sum=0,maxv=0;
    for(int i=1;i<=n;++i)if(b[i])sum+=x[i],maxv=max(x[i],maxv);
    if(maxv*2<sum)return true;
    return false;
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>x[i];
    while(!b[0])
    {
        int j=n;
        while(b[j])b[j--]=false;
        b[j]=true;
        if(check())ans=(ans+1)%p;
    }
    cout<<ans;
    return 0;
}
