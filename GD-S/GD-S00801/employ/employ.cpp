#include<bits/stdc++.h>
using namespace std;
const int maxn = 20,maxs = (1 << 18) + 10,mod = 998244353;
char b[maxn];
int c[maxn],a[maxn];
long long dp[2][maxn][maxs];
void made(long long&x,int y){
	(x += y) >= mod && (x -= mod);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d%s",&n,&m,b+1);
	int alcnt = 0;
	for(int i = 0;i < n;i++){
		scanf("%d",c+i);
		if(c[i])a[++alcnt] = i;
	}
	dp[0][0][0] = 1;
	int t = 1 << n;
	int now = 0,lst = 1; 
	for(int i = 0;i < n;i++){
		swap(lst,now);
		memset(dp[now],0,sizeof(dp[now]));
		for(int s = 0;s < t;s++)
			for(int j = 0;j < n;j++)
				for(int k = 0;k < n;k++)
					if(!(s & (1 << k)))
						made(dp[now][j+(b[i+1]!='0'&&c[k]>i-j)][s|(1<<k)],dp[lst][j][s]);
	}
	long long ans = 0;
	for(int s = 0;s < t;s++)
		for(int i = m;i <= n;i++)
			made(ans,dp[now][i][s]);
	cout << ans;
}
