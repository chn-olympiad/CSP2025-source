#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+50,mod=998244353;
int n;
int a[N],sj=0,maxn=INT_MIN,sum=0;
inline int qpow(int x,int y,int mod){
	int le=1;
	while(y!=0){
		if(y&1)le*=x%mod;
		y/=2;
		x*=x%mod;
	}
	return x*le%mod;
}
inline int j(int x){
	int sum=1;
	for(int i=1;i<=x;i++)sum*=i%mod;
	for(int i=1;i<=3;i++)sum/=i%mod;
	for(int i=1;i<=n-3;i++)sum/=i%mod;
	return sum%mod;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i];maxn=max(maxn,a[i]);sum+=a[i];}
	if(n<3)sj=0;
	else if(n==3&&maxn*2<sum)sj=1;
	else if(maxn==1)sj=(qpow(2,n-3,mod)%mod+j(n)%mod)%mod;
	else if(maxn*2<sum)sj=1;
	cout<<sj;
	return 0;
}
