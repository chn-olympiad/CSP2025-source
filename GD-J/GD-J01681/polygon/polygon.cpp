#include<bits/stdc++.h>
using namespace std;
long long ans=0;
const long long mod=998244353LL;
const int N=5020;
int n;
int a[N];
long long A(int n,int m){
	long long k=1;
	for(int i=1,j=n;i<=m;i++,j--){
		k*=j;
		k%=mod;
	}
	return k;
}
long long C(int n,int m){
	return 1LL*A(n,m)/A(m,m);
}
void dfs(int l,int r,int m,int cnt,int maxn){//[l,r]区间，返回法数量 
	if(m==0){
		ans+=cnt>2*maxn;
		ans%=mod;
		return;
	}
	for(int i=l;i<=r;i++){
		dfs(i+1,r,m-1,cnt+a[i],a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int m=3;m<=n;m++){
		dfs(1,n,m,0,0);
		ans%=mod;
	}
	cout<<ans%mod;
	return 0;
} 
