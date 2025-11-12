#include<bits/stdc++.h>
using namespace std;
int s[10000],n,ans;
void dfs(int sum,int ma,int i,int tot)
{
	if(i>n) return ;
	if(sum>=3&&2*s[i]<tot) ans=(ans+1)%998244353; 
	dfs(sum+1,s[i+1],i+1,tot+s[i+1]);
	dfs(sum,ma,i+1,tot);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	dfs(0,0,0,0);
	cout<<ans;
    return 0;
}
