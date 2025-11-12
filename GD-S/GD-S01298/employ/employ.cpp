#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <cassert>
#include <map>
#include <set>
#define int long long
using namespace std;

const int md=998244353;
void read(int &x){
	x=0;
	int f=1;
	char c=getchar();
	while(!('0'<=c && c<='9')){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while('0'<=c && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	x*=f;
}

int fact[510];
int n,m,s[510],a[510],sv[510],val[510],id[510];
int dp[2][510][510];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fact[0]=1;
	for(int i=1;i<=500;i++){
		fact[i]=fact[i-1]*i%md;
	}
	read(n);
	read(m);
	int cf=0;
	for(int i=1;i<=n;i++){
		scanf("%1lld",&s[i]);
		cf+=s[i];
		id[i]=i;
	}
	for(int i=1;i<=n;i++){
		read(a[i]);
		sv[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		sv[i]+=sv[i-1];
	}
	sort(a+1,a+n+1);
	dp[0][0][0]=1;
	for(int i=0;i<n;i++){
		memset(dp[(i+1)&1],0,sizeof(dp[0]));
		for(int j=0;j<=i;j++){
			for(int k=0;k<=i;k++){
				if(s[i+1]==0){
					dp[(i+1)&1][j+1][k]=(dp[(i+1)&1][j+1][k]+dp[i&1][j][k])%md;
				}else{
					dp[(i+1)&1][j+1][k+1]=(dp[(i+1)&1][j+1][k+1]+dp[i&1][j][k]*(sv[j]-k+md))%md;
					dp[(i+1)&1][j][k]=(dp[(i+1)&1][j][k]+dp[i&1][j][k])%md;
					dp[(i+1)&1][j][k+1]=(dp[(i+1)&1][j][k+1]+dp[i&1][j][k]*(k-sv[j]+md))%md;
				}
			}
		}
	}
	int res=0;
	for(int i=0;i<=n-m;i++){
		for(int j=0;j<=n;j++){
			res=(res+dp[n&1][i][j]*fact[n-j])%md;
		}
	}
	printf("%lld",res);
	return 0;
}
