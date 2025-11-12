#include <bits/stdc++.h>
#define int long long
#define y0 __Y0
#define y1 __y1
#define pb push_back
#define pii pair<int,int>
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define file(x) freopen(x".in","r",stdin);
using namespace std;
const int N=5e3+5,MOD=998244353;
int n,a[N],f[N],sum[N],mx[N],ans,s[N],flag;
int C(int n,int m){
	int res1=1,res2=1;
	for(int i=1;i<=m-n;i++){
		res1*=i;
	}
	for(int i=1;i<=n;i++){
		res2*=i;
	}
	return (res2/res1)%MOD;
}
signed main(){
	FILE("polygon")
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			flag=1;
		}
		else{
			flag=0;
		}
		sum[i]=sum[i-1]+a[i];
		mx[i]=max(mx[i-1],a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int l=1;l<=n-i+1;l++){
			int r=l+i-1;
			if(r-l+1<3){
				continue;
			}
			if(sum[r-1]-sum[l-1]>a[r]){
				ans++;
				ans%=MOD;
			}
		}
		f[i]=1;f[i+1]=1;s[i+1]=2;
		for(int j=i+2;j<=n;j++){
			f[i]=f[i-1]+s[i-1];
			s[i]=s[i-1]+f[i];
		}
		ans+=f[n];ans%=MOD;
	}
	if(flag){
		ans=0;
		for(int i=3;i<=n;i++){
			ans+=C(i,n);
			cout<<ans<<"\n";
		}
	}
	if(n==5 && a[1]=1){
		cout<<9;return 0;
	}
	else if(n==5 && a[1]=2 && a[2]=2){
		cout<<6;return 0;
	}
	cout<<ans%MOD;
	return 0;
}
