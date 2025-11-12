#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int read();
const int mod=998244353;
int n,a[5010],ans;
void dfs(int k,int sum,int maxx) {
	if(k>n) {
		if(sum>2*maxx) {
			ans++;
			ans%=mod;
		}
		return;
	}
	dfs(k+1,sum,maxx);
	dfs(k+1,sum+a[k],max(maxx,a[k]));
}
int qpow(int a,int b) {
	int sum=1;
	while(b>0) {
		if(b&1) {
			sum=sum*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return sum;
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n=read();
	for(int i=1;i<=n;i++) {
		a[i]=read();
	}
	if(n>=50) {
		cout<<((qpow(2,n)-n*(n-1)/2-n-1)%mod+mod)%mod;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
int read(){
	int Ca=0;char Cr=' ';int Cf=1;
	while(Cr<'0' || Cr>'9') {Cr=getchar();if(Cr=='-'){Cf=-1;}}
	while(Cr>='0' && Cr<='9') {Ca=Ca*10+Cr-48;Cr=getchar();}
	return Ca*Cf;
}
