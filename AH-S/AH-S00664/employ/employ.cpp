#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,a[600],c[600];
int t[600];
bool p[600],A=1;
char ch;
long long s,ans;
long long jc(int k){
	s=1;
	for(int i=2;i<=k;i++){
		s*=i;
		s%=mod;
	}
	return s;
}
void dfs(int k,int s){
	if(s>=m){
		ans+=jc(n-k+1);
		ans%=mod;
		return;
	}
	if(k>n){
		if(s>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(p[i]==0){
			p[i]=1;
			if(k-s-1>=c[i]||a[k]==0)
			dfs(k+1,s);
			else dfs(k+1,s+1);
			p[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch;
		if(ch=='1')a[i]=1;
		else a[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans%mod;
	return 0;
}
