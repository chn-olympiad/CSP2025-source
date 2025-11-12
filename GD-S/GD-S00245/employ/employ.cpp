#include<bits/stdc++.h>
using namespace std;
const int N=500;
const int mod=998244353;
int n,m,ans;
char str[N];
int tong[N];
int c[N][N];
void getc(int n){
	c[0][0]=c[1][0]=c[1][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(j==0||j==i) c[i][j]=1;
			else c[i][j]=c[i-1][j]+c[i-1][j-1];
			c[i][j]%=mod ;
		}
	}
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>str[i]; 
	}
	for(int i=1;i<=n;i++){
		cin>>tong[i];
	}
	ans=1;
	getc(n);
//	cout<<c[n][m]<<endl;
	for(int i=m;i>=1;i--){
		ans*=i;
		ans%=mod;
	}
	ans=(ans*c[n][m])%mod;
	cout<<ans;
	return 0; 
}
