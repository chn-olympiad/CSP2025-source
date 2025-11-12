#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a[5005],sticksum;
bool cmp(int x,int y)
{
    return x>y;
}
void dfs(int p,int sum,int maxsum)
{
    if(p==n+1)
    {
        if(sum>2*maxsum)
            sticksum=(sticksum+1)%mod;
        return;
    }
    if(maxsum==0)
        dfs(p+1,sum+a[p],a[p]);
    else
        dfs(p+1,sum+a[p],maxsum);
    dfs(p+1,sum,maxsum);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,cmp);
    dfs(1,0,0);
    cout<<sticksum%mod<<endl;
    return 0;
}
