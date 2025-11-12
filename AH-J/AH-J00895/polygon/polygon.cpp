#include<bits/stdc++.h>
using namespace std;
const int inf=998244353;
vector<long long> c(5001);
long long ans=0,n;
void dfs(long long now,long long be)
{
    if(now>2*c[be]){
        ans++;
        ans%=inf;
    }
    for(int i=be+1;i<=n;i++)
    {
        dfs(now+c[i],i);
    }
    return;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> c[i];
    }
    sort(c.begin()+1,c.begin()+n+1);
    dfs(0,0);
    cout << ans%inf;
    return 0;
}
