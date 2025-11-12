//64 YangShao_Culture
#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int N=5005;
int n,a[N];
int k,g[N];
int c[N][N];
void init(){
	c[1][1]=1;
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n+1;j++){
			if(i==1&&j==1)	continue;
			c[i][j]=(c[i][j-1]+c[i-1][j])%MOD;
		}
	}
}
void solve(){
	cin>>n;
	if(n>20){
		init();
		long long ans=0;
		for(int i=3;i<=n;i++){
			int I=n-i+1;
			int J=i+1;
			ans=(ans+c[I][J])%MOD;
		}
		cout<<ans;
		return ;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g[i]=(1<<(i-1));
		k+=g[i]; 
	} 
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=0;i<=k;i++){
		int sum=0,mx=0;
		for(int j=1;j<=n;j++){
			if(i&g[j]){
				sum+=a[j];
				mx=a[j];
			}
		}
		if(sum>2*mx)	ans++;
	}
	cout<<ans;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	solve();
	return 0;
} 
