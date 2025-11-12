#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=5e3+10,M=2e3+10;
const ll P=998244353;
ll qp(ll a,ll b){
	ll res=1;
	for(;b;b>>=1,a=(a*a)%P)if(b&1)
		res=(res*a)%P;
	return res; 
}
int n,a[N],s[N],m[N];
ll f[N*N],g[N*N],ans;
int tn(int i,int j){ return i*s[n]+j; }
bool sub1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	sub1=1;
	for(int i=1;i<=n;i++)
		cin>>a[i],
		s[i]=s[i-1]+a[i],
		m[i]=max(m[i-1],a[i]),
		sub1&=(a[i]==1);
	if(sub1){
		ll Cn2=0;
		Cn2=((ll)n*(ll)(n-1)/2ll)%P;
		cout<<((qp(2,n)-1-n+P)%P-Cn2+P)%P;
		return 0;
	}
	f[tn(0,0)]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++)
			for(int k=0;k<=s[i];k++)
				g[tn(j,k)]=f[tn(j,k)];
		for(int j=0;j<=i;j++){
			for(int k=a[i];k<=s[i];k++){
				int mxp=i;
				if(a[j]>a[i])mxp=j;
				(f[tn(mxp,k)]+=g[tn(j,k-a[i])])%=P;
			}
		}
	}
	for(int j=0;j<=n;j++)
		for(int k=2*a[j]+1;k<=s[n];k++)
			(ans+=f[tn(j,k)])%=P;
	cout<<ans; 
	return 0;
}
