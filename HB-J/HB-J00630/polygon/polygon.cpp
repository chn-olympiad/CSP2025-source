#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e3+5;
const int mod=998244353;

int n,a[N];
int cnt;

void dfs(int i,int sum,int maxn,int len)
{
    if(i==n+1)
    {
        if(len>=3&&sum>maxn*2)
            cnt++,cnt%=mod;
        return;
    }
    dfs(i+1,sum+a[i],max(maxn,a[i]),len+1);
    dfs(i+1,sum,maxn,len);
}

signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1,0,0,0);
    cout<<cnt;
}
