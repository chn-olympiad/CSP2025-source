#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[505],c[505],d[505],vis[505],viss[505];
int n,m,ans;
bool check(){
	int cnt=0;
	int tmp[505]={0};
	for(int i=1;i<=n;i++){
		tmp[i]=d[i];
	}
	for(int i=1;i<=n;i++){
		if(c[viss[i]]>d[i-1] && a[i]==1){
			cnt++;
		}
	}
	return cnt>=m;
}
void dfs(int x){
	if(x==n+1){
		if(check()){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!viss[i]){
			vis[x]=i;
			viss[i]=1;
			dfs(x+1);
			viss[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[i+1]=s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans%mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
