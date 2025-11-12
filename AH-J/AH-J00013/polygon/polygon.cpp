#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5005;
int n;
int ans;
int a[N];
bool flag=1;
void dfs(int now,int maxn,int sum,int cnt){
	if(cnt>=3&&sum>2*maxn){
		ans=(ans+1)%mod;
	}
	for(int i=now+1;i<=n;i++){
		dfs(i,max(maxn,a[i]),sum+a[i],cnt+1);
	}
}
int mxl(int n){
	int outans=1;
	for(int i=1;i<=n;i++){
		outans=outans*i%mod;
	}
	return outans;
}
int A(int n,int m){
	return (mxl(n)%mod)/((mxl(n-m)%mod)*mxl(m)%mod)%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]>1){
			flag=0;
		}
	}
	if(flag==0){
		dfs(0,0,0,0);
	}else{
		for(int i=3;i<=n;i++){
			ans=(ans+A(n,i))%mod;
		}
	}
	cout << ans;
	return 0;
}
