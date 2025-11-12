#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],t,mi[505]={1},v[505];
string s;
void dfs(long long r,long long a){
	if(r-a>=m){
		t=(t+mi[n-r])%998244353;
		return;
	}
	if(n-a<m) return;
	for(int i=1;i<=n;i++) if(!v[i]){
		v[i]=1;
		if(c[i]>a) dfs(r+1,a+49-s[r]);
		else dfs(r+1,a+1);
		v[i]=0;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(long long i=1;i<=n;i++) scanf("%lld",&c[i]);
	for(long long i=1;i<=n;i++) mi[i]=i*mi[i-1]%998244353;
	dfs(0,0);
	printf("%lld",t);
	return 0;
}
