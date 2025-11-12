#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,a[N],mod=998244353,ma,sum,ans,c[5010][5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	c[1][0]=c[1][1]=1;
	for(int i=1;i<=5000;i++)c[i][0]=c[i][i]=1;
	for(int i=2;i<=5000;i++){
		for(int j=1;j<i;j++){
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	}
	for(int i=1;i<=n;i++)ans=(ans+c[n][i])%mod;
	cout<<ans<<endl;
	return 0;
} //#Shang4Shan3Ruo6Shui4
/*
5
2 2 3 8 10
*/
