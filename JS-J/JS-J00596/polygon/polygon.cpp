#include <bits/stdc++.h>
using namespace std;
const int M=5e3+10;
const int Mod=998244353;
int n;
int a[M];
int ans;
void dfs(vector<int> vec,int k)
{
    if(k>n)
    {
        if(vec.size()<3) return ;
        int maxn=0,sum=0;
        for(auto i:vec)
        {
            sum+=i;
            maxn=max(maxn,i);
        }
        if(sum>(2*maxn)) ans++;
        ans%=Mod;
        return ;
    }
    dfs(vec,k+1);
    vec.push_back(a[k]);
    dfs(vec,k+1);
    return ;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    dfs({},1);
    cout<<(ans%Mod)<<endl;
    return 0;
}
