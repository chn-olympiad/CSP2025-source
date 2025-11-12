#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
bool aaa;
int n,a[5010];
ll f[5010][11010];
inline int max(int a,int b){
	return a>b?a:b;
}
int la[5010];
bool bbb;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int xm=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xm=max(xm,a[i]);
		la[i]=i-1;
	}
	int m=xm*2+1;
	f[0][0]=1;
	sort(a+1,a+1+n);
	ll ans=0,cnt;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1])la[i+1]=la[i];
		memcpy(f[i],f[i-1],sizeof(f[i])); 
		f[i][m]=f[i][m]<<1;
		for(int j=m-1;j>=m-a[i]&&j>=a[i];j--){
			f[i][m]=(f[i][m]+f[i-1][j])%mod;
		}
		for(int j=m-1;j>=a[i];j--){
			f[i][j]=(f[i][j]+f[i-1][j-a[i]])%mod;
		}
		ll s=0;
		for(int j=a[i]*2+1;j<=m+1;j++){
			s=(s+f[i][j]-f[la[i]][j]+mod)%mod;
		}
		if(a[i]!=a[i+1])ans=(ans+s)%mod; 
	} 
	cout<<ans;
	return 0;
}
/*
I AK CSP-J
I AK CSP-S
I AK NOIP
I AK GDOI
I AK NOI
I AK IOI
hahahahahahahahahaha
*/
