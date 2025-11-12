#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],s;
bool f=1;
int qp(int x){
	if(x==1)return 2;
	if(x==0)return 1;
	int u=qp(x/2);
	if(x&1)return u*u%mod*2%mod;
	else return u*u%mod;
}
void dfs(int k,int sum,int mx){
	if(k>n){
		if(sum>mx*2)s=(s+1)%mod;
		return;
	}
	dfs(k+1,sum,mx);
	dfs(k+1,sum+a[k],a[k]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)f=0;
	}
	if(f){
		s=qp(n)-n*(n-1)/2-n-1;
		if(s<0)s+=mod;
		cout<<s;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<s;
	return 0;
}
