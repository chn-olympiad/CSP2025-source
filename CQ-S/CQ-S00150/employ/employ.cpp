#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,a[600],use[600],c[600],ss,ans;
string s;
void dfs(int id){
	if(id>n){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(i-1-sum<a[c[i]]&&s[i-1]=='1') sum++;
		}
		if(sum>=m) ans++,ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(use[i]) continue;
		c[id]=i,use[i]=1;
		dfs(id+1);
		c[id]=0,use[i]=0;
	}
	return ;
}
int sss(int n){
	int ans=1;
	for(int i=1;i<=n;i++) ans*=i,ans%=mod;
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		if(s[i]=='1') ss++;
	}
	if(ss<m){
		//??pts
		cout<<0;
		return 0;
	}
	if(ss==n){
		//20pts
		cout<<sss(n);
		return 0;
	}
	if(n<=10){
		//8pts
		dfs(1);
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
/*
15:24 翻来覆去还是做T4吧
15:57 NO,有问题!!!
保佑我蓝勾，球球了，给我蓝勾吧 
*/
