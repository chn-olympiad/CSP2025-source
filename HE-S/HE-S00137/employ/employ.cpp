#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,c[555],pro[555],fac[555],ans,a[555];
string s;
bool flag=0,vis[555];
void dfs(int cnt){
	if(cnt==n+1){
		int sum=0,leave=0;
		for(int i=1;i<=n;i++){
			if(pro[i]==0)leave++;
			else if(a[i]>leave)sum++;
			else leave++;
			//cout<<leave<<" "<<sum<<"\n";
		}
		if(sum>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			a[cnt]=c[i];
			vis[i]=1;
			dfs(cnt+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		pro[i+1]=s[i]-'0';
		if(pro[i+1]!=1)flag=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(!flag){
		fac[1]=1;fac[0]=1;
		for(int i=1;i<=n;i++){
			fac[i]=fac[i-1]*i%mod;
		}
		cout<<fac[n];
		return 0;
	}
	if(m==n&&flag){
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
