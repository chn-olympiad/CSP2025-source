#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510,mod=998244353;
ll M(ll a,ll b){
	ll s=1;
	while(b){
		if(b&1)
			s=s*a%mod;
		a=a*a%mod;
		b>>=1;}
	return a;
}
ll x[N],x2[N],f[N][N],ans;
char c[N];
int n,m;
int a[N],b[N],k[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	x[0]=1;
	for(int i=1;i<=n;i++)
		x[i]=x[i-1]*i%mod;
	x2[n]=M(x[n],mod-2);
	for(int i=n-1;i>=0;i--)
		x2[i]=x2[i+1]*(i+1)%mod;
	cin>>(c+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]--;
		if(a[i]>=0)
			b[a[i]]++;}
	for(int i=n-1;i>=0;i--)
		b[i]+=b[i+1];
	if(b[0]<m){
		cout<<0<<endl;
		return 0;}
	if(b[0]==n){
		cout<<x[n]<<endl;
		return 0;}
	cout<<0<<endl;
	return 0;
}
