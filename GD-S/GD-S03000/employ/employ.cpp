#include<bits/stdc++.h>
using namespace std;
const int N=500+10,mod=998244353;
int n,m,ans;
long long c[N][N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	ans=n;
	for(int i=1,aa;i<=n;i++){
		cin>>aa;
		if(aa==0)ans--;
	}
	for(int i=0;i<=n;i++){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<=i;j++){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	} 
	if(s[n-1]=='1'){
		long long nn=1,aaa=0;
		if(ans<m){
			cout<<0;
			return 0;
		}
		for(int i=2;i<=m;i++){
			nn=nn*i%mod;
		}
		aaa=c[ans][m]*nn%mod;
		for(int i=m+1;i<=ans;i++){
			nn=nn*i%mod;
			aaa=(aaa+c[ans][i]*nn%mod)%mod;
		}
		cout<<aaa;
		return 0;
	}
	cout<<0;
	return 0;
}

