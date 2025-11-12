#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],d[505],k;
string s;
void dfs(int x){
	if(x==n)
	{
		int t=0;
		for(int i=0;i<n;++i)
		{
			if(s[i]=='0'||t>=d[i+1]) ++t;
			if(n-t<m) return ;
		}
		++k;
		k%=998244353;
		return ;
	}
	for(int i=1;i<=n;++i)
	{
		if(d[i]==-1)
		{
			d[i]=c[++x];
			dfs(x);
			d[i]=-1;
			--x;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	memset(d,-1,sizeof(d));
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++)
	{
		k+=(s[i]=='0');
	}
	for(int i=1;i<=n;++i)
	{
		cin>>c[i];
		k+=(c[i]==0);
	}
	if(n-k<m) cout<<0;
	else
	{
		dfs(0);
		cout<<k;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
