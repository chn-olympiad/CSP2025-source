#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505],ans,use[505];
string s;
void dfs(int now,int sum,int f){
	if((n-now)<(m-sum)) return; 
	if(sum==m){
		int tmp=1;
		for(int i=now+1;i<=n;i++) tmp*=(i-now);
		ans+=tmp;
		ans%=mod;
		return;
	}
	if(now==n){
		if(sum>=m) ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!use[i]){
			use[i]=1;
			if(f<c[i]&&s[now]=='1') dfs(now+1,sum+1,f);
			else dfs(now+1,sum,f+1);
			use[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	int sum=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') sum++;
	}
	if(sum<m){
		cout<<0;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans;
}
