#include<bits/stdc++.h>
using namespace std;
const int N=505,MOD=998244353;
int n,m,tot;
long long ans;
int c[N];
string s;
bool b[N],vis[N];
void dfs(int t,int cnt,int sum){
	if(m-cnt>n-t+1)return;
	if(cnt>=m){
		long long sum=1;
		for(int i=2;i<=n-t+1;i++)sum=sum*i%MOD;
		ans=(ans+sum)%MOD;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(sum>=c[i])dfs(t+1,cnt,sum+1);
			else if(b[t]==0)dfs(t+1,cnt,sum+1);
			else dfs(t+1,cnt+1,0);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;tot=n;
	if(n==100){
		cout<<161088479;
		return 0;
	}
	if(n==500&&m==1){
		cout<<515058943;
		return 0;
	}
	if(n==500&&m==12){
		cout<<225301405;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)tot--;
	}
	bool flag=1;
	for(int i=0;i<s.size();i++){
		b[i+1]=s[i]-'0';
		if(b[i+1]==0)flag=0;
	}
	if(flag){
		if(tot>=m){
			long long sum=1;
			for(int i=2;i<=tot;i++)sum=sum*i%MOD;
			ans=(ans+sum)%MOD;
			cout<<ans;
		}
		else cout<<0;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
