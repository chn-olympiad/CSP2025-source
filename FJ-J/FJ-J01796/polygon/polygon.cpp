#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010,Mod=998244353;
int a[N],Pow[N];
int f[N][N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	Pow[0]=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		Pow[i]=Pow[i-1]*2%Mod;
	}
	sort(a+1,a+1+n);
	int ans=0;
	f[0][0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<=a[n]+1;j++){
			if(j>a[i]){
				f[i][j]=(f[i-1][j-a[i]]+f[i-1][j])%Mod;
			}
			else{
				f[i][j]=(Pow[i-1]+f[i-1][j])%Mod;
			}
		}
		ans+=f[i-1][a[i]+1];
		ans%=Mod;
	}
	ans+=f[n-1][a[n]+1];
	ans%=Mod;
	cout<<ans<<'\n';
	return 0;
}
