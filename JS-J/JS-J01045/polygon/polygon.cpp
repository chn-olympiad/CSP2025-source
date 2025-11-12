#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100000];
int n;
int ans=0;
vector<int> v;
void dfs()
{
    if(v.size()==n)
    {
        int mx=0;
        int sum=0;
        for(int i=0;i<v.size();i++)if(v[i])
        {
            mx=max(mx,a[i]);
            sum+=a[i];
        }
        if(sum>2*mx)ans=(ans+1)%998244353;
        return;
    }
    v.push_back(1);
    dfs();
    v.back()=0;
    dfs();
    v.pop_back();
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    dfs();
    cout<<ans;
    return 0;
}
