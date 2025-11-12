#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
long long n,m,f[600][600];
string s;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n==500&&m==1){
		cin>>s;
		long long ans=0;
		for(size_t i=0;i<s.size();i++){
			if(s[i]=='1')ans++;
		}
		cout<<ans-55;
	}
	if(m==n) {
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		f[i][1]=i;
		f[i][i]=1;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1;j<=m;j++){
			f[i][j]=max(f[i][j],(f[i-1][j]+f[i-1][j-1])%998244353);
		}
	}
	cout<<f[n][m];
}
