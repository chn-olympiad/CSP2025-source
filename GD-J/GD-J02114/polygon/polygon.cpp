#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5005;
int n,ans;
int a[N],b[N],c[N+1][N+1];
bool v[N];
void init(){
	for(int i=1;i<=n;i++)c[i][1]=i,c[i][i]=1;
	for(int i=3;i<=n;i++){
		for(int j=2;j<i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
}
main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	init();
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(int i=3;i<=n;i++){
		ans=(ans+c[n][i])%mod;
	}
	cout<<ans<<endl;
	return 0;
}
