#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m;
char s[550];
int c[550];
int vis[550];
long long ans=0;
int jishu=0;
inline void chk(){
//	jishu++;
	int sum=0;
//	for(int i=1;i<=n;i++){
//		cout<<vis[i]<<"*";
//	}
//	cout<<endl;
	for(int i=1;i<=n;i++){
		if(c[vis[i]]<=i-sum-1)continue;
		if(s[i]=='1')sum++;
	}
//	cout<<sum<<endl;
	if(sum>=m)ans++;
}
inline void dfs(int x){
	if(x==n+1){
		chk();
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=x;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
inline void workA(){
	ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%mod;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>(s+1);
	bool flag=false;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;s[i];i++){
		if(s[i]=='0'){
			flag=true;
			break;
		}
	}
	if(flag==false)workA();
	else dfs(1);
	cout<<ans<<endl;
//	cout<<jishu<<endl;
}
