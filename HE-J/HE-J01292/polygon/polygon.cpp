#include <bits/stdc++.h>
using namespace std;
int n;
int a[5050],c[5050];
int q[5050];
int k,w,p,sum;
long long ans;
inline void dfs(int s,int b){
	if(s>w) return;
	if(b==k){
		sum=0;
		for(int i=1;i<=k;i++){
			sum+=c[i];
			if(sum>p){
				ans++;
				ans%=998244353;
				return;
			}
		}
		return;
	}
	for(int i=s;i<=w;i++){
		c[b+1]=a[i];
		dfs(i+1,b+1);
	}
	return;
}
inline void solve(){
	if(n==3){
		cout<<1;
		return;
	}
	ans=1;
	long long m=n*(n-1),z=2;
	for(int i=2;i<n-1;i++){
		m*=(n-i);
		z*=(i+1);
		m%=998244353;
		z%=998244353;
		ans+=m/z;
		ans%=998244353;
	}
	cout<<ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=false;
	}
	if(flag){
		solve();
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
	}
	for(int i=3;i<=n;i++){
		p=a[i];
		w=i;
		if(q[i-1]<=a[i]) continue;
		for(int j=2;j<i;j++){
			k=j;
			dfs(1,0);
		}
	}
	cout<<ans;
	return 0;
}
