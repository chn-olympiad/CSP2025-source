#include<bits/stdc++.h>
#define elif else if
//#define int long long
using namespace std;
//const MOD=998244353;
int n,a[114514/10],ans;
//int c(int nm,int mn){
//	int s=1,cnt=;
//	for(int i=nm;i>mn;i--) s*=i;
//	for(int i=nm-mn;i>0;i--) s/=i;
//	return s;
//}
void dfs(int now,int sum,int ge,int maxx){
	if(now==n){
		if(sum>maxx*2&&ge>2) ans++;
		return;
	}
	dfs(now+1,sum+a[now],ge+1,max(maxx,a[now]));
	dfs(now+1,sum,ge,maxx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
//	if(sum==n){
//		for(int i=3;i<=n;i++) ans+=c(n,i);
//		cout<<ans;
//	}
//	else{
	dfs(0,0,0,0);
	cout<<ans;
//	}
	return 0;
}//#Shang4Shan3Ruo6Shui4
