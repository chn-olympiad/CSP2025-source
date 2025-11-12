#include<bits/stdc++.h>
#define N 5010
#define A 10100
#define mod 998244353
#define int long long
using namespace std;
int f[N],g[A],ans,n,a[N],pw[N];

int read(){
	int sum=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		sum=sum*10+c-'0';
		c=getchar(); 
	}
	return sum;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cin>>n;
	n=read();
	pw[0]=1;
	for(int i=1;i<=n;i++){
		pw[i]=pw[i-1]<<1;
		pw[i]%=mod;
	}
	int mx=0;
	for(int i=1;i<=n;i++){
//		cin>>a[i];
		a[i]=read();
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=0;i<=mx;i++) g[i]=1;
	for(int j=mx;j>=a[1];j--){
		g[j]+=g[j-a[1]];
	}
	for(int j=mx;j>=a[2];j--){
		g[j]+=g[j-a[2]];
	}
	for(int i=3;i<=n;i++){
		f[i]=pw[i-1]-g[a[i]]+f[i-1];
		f[i]=(f[i]+mod)%mod;
		for(int j=mx;j>=a[i];j--){
			g[j]+=g[j-a[i]];
			g[j]%=mod;
		}
	}
	cout<<f[n];
	return 0;
}
