#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e4+5,N1=5e3+5,MOD=998244353;
int n,a[N];
unsigned int f[N][M],s[N][M],f1[N1][N1],s1[N1][N1];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(a[1]==1&&a[n]==1){
		f1[0][0]=s1[0][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=a[i]*i;j++){
				f1[i][j]=s1[i-1][j-a[i]];
				s1[i][j]=(s1[i-1][j]+f1[i][j])%MOD;
			}
		int ans=0;
		for(int i=3;i<=n;i++)
			for(int j=a[i]*2+1;j<=a[i]*i;j++)
				ans=(ans+f1[i][j])%MOD;
		cout<<ans;		
	}
	else{
		f[0][0]=s[0][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=a[i]*i;j++){
				f[i][j]=s[i-1][j-a[i]];
				s[i][j]=(s[i-1][j]+f[i][j])%MOD;
			}
		int ans=0;
		for(int i=3;i<=n;i++)
			for(int j=a[i]*2+1;j<=a[i]*i;j++)
				ans=(ans+f[i][j])%MOD;
		cout<<ans;
	}
	return 0;
}