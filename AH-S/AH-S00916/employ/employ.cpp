#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[505],n,m;
bool vis[505];
char s[505];
int ans=0;
void dfs(int st,int sum){
	if(st==n+1){
		if(sum>=m){
			ans+=1;
		}
		return ;
	}
	if(n-st+1+sum<m){
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]) {
			vis[i]=true;
			dfs(st+1,sum+(s[st]=='1'&&(st-sum-1)<=a[i]));
			vis[i]=false;
		}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	bool flag=false;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]!=1) flag=true;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	if(flag==false){
		int sum=1;
		for(int i=n;i>=n-m+1;i--)
			sum=(sum*i/(n-i+1))%998244353;
		cout<<sum;
	}
	else{
		dfs(1,0);
		cout<<ans;
	}
	return 0;
}
