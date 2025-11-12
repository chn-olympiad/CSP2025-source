#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5005];
int ans;
void dfs(int x,int sum,int stick,int maxs)//now stick,the sumerise of sitcks' length,the number of stick,the max length belong the sticks
{
    if(stick>=3&&sum>maxs*2)
        ans=(ans+1)%mod;
    if(x>n) return;
    dfs(x+1,sum+a[x+1],stick+1,max(maxs,a[x+1]));
    dfs(x+1,sum,stick,maxs);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(0,0,0,0);
    cout<<ans%mod<<endl;
    return 0;
}