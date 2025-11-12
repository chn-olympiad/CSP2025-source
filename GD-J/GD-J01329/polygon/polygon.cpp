#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,p,a[10000];
long long ans;
long long qpow(long long l,int k){
	long long cnt=1;
	while(k){
		if(k&1) cnt=cnt*l%mod;
		l=l*l%mod;
		k>>=1;
	}
	return cnt;
}
void dfs(int cnt,int m,int s,int nw,bool p){
	if(s>=3&&cnt>2*m&&p==1) {
		ans++;
		ans%=mod;
	}
	if(nw==n+1) return;
	dfs(cnt,m,s,nw+1,0);
	dfs(cnt+a[nw],max(m,a[nw]),s+1,nw+1,1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p=max(p,a[i]);
	}
	if(p==1) {
		cout<<qpow(2,n)-1-n-n*(n-1)/2;
		return 0;
	}
	dfs(0,0,0,1,0);
	cout<<ans;
	return 0;
}
