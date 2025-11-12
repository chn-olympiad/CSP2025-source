#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int n;
int a[N];
int ans;
void dfs(int dep,int sum,int maxn,int cnt)
{
    if(dep>n)
    {
        if(cnt>=3&&sum>2*maxn)ans++;
        return;
    }
    dfs(dep+1,sum,maxn,cnt);
    dfs(dep+1,sum+a[dep],max(maxn,a[dep]),cnt++);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    int f=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1) f=0;
    }
    if(n==3)
    {
        cout<<(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])) ? 1 : 0);
        return 0;
    }
    if(f)
    {
        cout<<n-2;
        return 0;
    }
    dfs(1,0,-1,0);
    cout<<ans;
    return 0;
}