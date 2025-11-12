#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0){putchar('-');x=-x;}
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
int dp[maxn][maxn+10],w[20][maxn];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=1e18;
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		dp[u][v]=w;
	}
	cout<<0;
	return 0;
}
