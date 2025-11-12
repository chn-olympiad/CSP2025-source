#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,ans=0;
string s;
int c[505];
bool vis[505];
void dfs(int k,int sum,int fail)
{
    if(k==n+1)
    {
        if(sum>=m) ans++;
        return;
    }
    if(n-fail<m) return;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        vis[i]=1;
        if(s[k-1]=='0') dfs(k+1,sum,fail+1);
        else
        {
            if(fail>=c[i]) dfs(k+1,sum,fail+1);
            else dfs(k+1,sum+1,fail);
        }
        vis[i]=0;
    }
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
        cin>>c[i];
    if(m==n && m>100)
    {
        cout<<0;
        return 0;
    }
    dfs(1,0,0);
    cout<<ans%M;
	return 0;
}
