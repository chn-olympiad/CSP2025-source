#include<bits/stdc++.h>
using namespace std;
const int N=600;
int n,m;
string s;
int c[N];
int a[N];
int f[N];
int ans=0;
void dfs(int x,int sum)
{
	if(sum+n-x+1<m)return ;
	if(sum>=m)
	{
		int ss=1;
		for(int i=1;i<=n-x+1;i++)ss*=i;
		ans+=ss;
		return ;
	}
	if(x>n)return ;
	for(int i=1;i<=n;i++)
		if(!f[i])
		{
			a[x]=i,f[i]=1;
			int cnt=0;
			if(x-1-sum<c[i]&&s[x-1]=='1')cnt=1;
			dfs(x+1,sum+cnt);
			f[i]=0;
		}
	return ;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}

