#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1;
bool pd[510];
int c[510];
bool u[510];
int k[510];
void dfs(int t){
	if(t==n+1){
		int ul=0;
		for(int i=1;i<=n;i++){
			if(pd[i]==0||ul>=c[k[i]])ul++;
		}
		if(n-ul>=m)ans++;
		ans=ans%998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(u[i]==0){
			u[i]=1;
			k[t]=i;
			dfs(t+1);
			u[i]=0;
			k[t]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)pd[i]=s[i-1]-'0';
	for(int i=1;i<=n;i++)cin>>c[i];
	int pdl=1;
	for(int i=1;i<=n;i++){
		if(pd[i]==0)pdl=0;
		ans=ans*i%998244353;
		ans=ans%998244353;
	}
	if(pdl==1){
		ans=ans%998244353;
		cout<<ans;
	}
	else {
		ans=0;
		dfs(1);
		cout<<ans;
	}
	return 0;
}
