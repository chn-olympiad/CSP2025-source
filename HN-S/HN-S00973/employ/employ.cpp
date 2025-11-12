#include<bits/stdc++.h>
using namespace std;
long long n,m,a[510],vis[510],ans=0;
string s;
long long b[510];
void dfs(int step){
	if(step==n){
		int cnt=0,num=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0'||cnt>=a[b[i]]) cnt++;
			else num++;
		}
		if(num>=m){
			ans++;
		}
	}
	for(int i=0;i<n;i++){
		if(vis[i]==1)continue;
		b[step]=i;
		vis[i]=1;
		dfs(step+1);
		b[step]=0;
		vis[i]=0; 
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i=0;i<n;i++) cin >> a[i];
	int f=0,op=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') f=1;
		if(a[i]==0) op++;
	}
	if(m==n&&f==1) cout << 0;
	else if(f==0){
		ans=1;
		for(int i=n-op;i>n-op-m;i--){
			ans=ans*i;
			ans=ans%998244353;
		}
	}
	else if(m==1){
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){
				f=i;
			}
		}
		int num=0;
		for(int i=0;i<n;i++){
			if(a[i]>=f) num++;
		}
		ans=1;
		for(int i=n-op;i>n-op-m;i--){
			ans=ans*i;
			ans=ans%10000000000000000;
		}
		ans=(ans/n*num)%998224353;
	}
	else{
		dfs(0);
	}
	cout << ans;
	return 0;
} 
