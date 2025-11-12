#include <iostream>
using namespace std;
inline int read(){
	int f=1,s=0;
	char t=getchar();
	while(t<'0'||t>'9'){
		if(t=='-'){
			f=-1;
		}
		t=getchar();
	}
	while(t>='0'&&t<='9'){
		s=s*10+t-'0';
		t=getchar();
	}
	return f*s;
}
const int N=5e5+10,M=1e3+10;
int n,k;
int dp[M][M],xosum[M][M];
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		dp[i][i]=int(a[i]==k);
		xosum[i][i]=a[i];
	}
	for(int len=1;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			xosum[l][r]=xosum[l][l]^xosum[l+1][r];
			dp[l][r]=int(xosum[l][r]==k);
			for(int k=l;k<r;k++){
				dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
			}
		}
	}
	cout<<dp[1][n];
	return 0;
}//#Shang4Shan3Ruo6Shui4
