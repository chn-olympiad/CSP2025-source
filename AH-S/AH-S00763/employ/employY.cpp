#include<bits/stdc++.h>
using namespace std;
const int N=305;
long long A[N];
int c[N],t[N];
string s;
const int MOD=998244353;
long long dp[N][N][N];
int main(){
	int n,m;
	cin>>n>>m;
	cin>>s;
	A[0]=1;
	for(int i=1;i<=n;i++){
		A[i]=1LL*i*A[i-1];
		A[i]%=MOD;
		scanf("%d",&c[i]);
		//c[i]++;
		t[c[i]]++;
	}
	for(int i=1;i<=n;i++){
		t[i]+=t[i+1];
	}
	t[0]=n;
	dp[0][0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=j;k<=i;k++){
				cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
				for(int x=0;x<2;x++){
					for(int y=x;y<2;y++){
						if(s[i]=='0'&&y){
							continue;
						}
						int b=i-j,c=i-k;
						if(y)dp[i+1][j+x][k+y]+=1LL*dp[i][j][k]*max((t[b+1]-c),0);
						else dp[i+1][j+x][k+y]+=dp[i][j][k];
						cout<<i<<' '<<j<<' '<<k<<' '<<x<<' '<<y<<' '<<b<<' '<<c<<' '<<t[b+1]<<' '<<c<<endl;
						dp[i+1][j+x][k+y]%=MOD;
					}	
				}
			}
		}
	}
	long long ans=0;
	for(int i=m;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((j-i)&1){
				ans-=dp[n][i][j]*A[n-j];
				ans%=MOD;
			}else{
				ans+=dp[n][i][j]*A[n-j];
				ans%=MOD;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
