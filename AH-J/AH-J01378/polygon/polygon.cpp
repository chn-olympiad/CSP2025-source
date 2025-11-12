#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt;
bool v[5005];
const int mod=998244353;
void dfs(int step,int sum,int num,int ii)
{
    if(sum>num*2)
    {
        cnt=cnt%mod+1;
    }
    if(step>n)return;
    for(int i=ii+1;i<=n;i++)
    {
        if(!v[i])
        {
            v[i]=1;
            dfs(step+1,sum+a[i],max(num,a[i]),i);
            v[i]=0;
        }
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1,0,0,0);
    cout<<cnt%mod;
    return 0;
}
