#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long ans;
int n;
int a[5005];
bool vis[5005];
void f(int i, int num, int Max, int pos, int reduce){
	if(i==pos+1){
		if(num>Max*2){
			ans++;
			ans=(long long)ans%mod;
		}
		return ;
	}
	for(int j=reduce;j>=1;j--){
		if(vis[j]) continue;
		vis[j]=1;
		f(i+1, num+a[j], max(Max, a[j]), pos, j-1);
		vis[j]=0;
		if(i==1) vis[j]=1;
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1, a+1+n);
	for(int k=3;k<=n;k++){
		memset(vis, 0, sizeof(vis));
		f(1, 0, 0, k, n);
	}
	ans=ans%mod;
	cout<<ans;
	return 0;
}
