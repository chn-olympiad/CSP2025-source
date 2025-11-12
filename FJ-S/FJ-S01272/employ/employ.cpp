#include<bits/stdc++.h>
using namespace std;

int n,m,c[100000];
string s;
long long ans;
bool vis[100000];
void dfs(int step)
{
	if(step>m){
	ans++;
	return ;
}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
		vis[i]=true;
		dfs(step+1);
		vis[i]=false;
		dfs(step+1);
	}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	
	if(m==1){
		for(int i=0;i<=s.size();i++){
			if(s[i]=='1')
			{
				for(int j=1;j<=n;j++)
				if(c[i]>i+1)
				ans++;
				cout<<ans%998244353;
				return 0;
			}
		}
	}
	
	dfs(0);
	cout<<ans%998244353;
	return 0;
}
