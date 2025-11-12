#include<bits/stdc++.h>
#define N 2005
#define ll long long
#define mod 998244353
#define wk(x) write(x),putchar(' ')
#define wh(x) write(x),putchar('\n')
using namespace std;
ll n,m,k,jk,ans,sum,num,cnt,tot;
ll head[N],dis[N],vis[N],wis[N],kis[N],f[N];
char a[N];

void read(ll & x){
	x=0;ll ff=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')) ff=(ch=='-'?-1:ff),ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	x*=ff;return;
}

void write(ll x){
	if(x<0){x=-x;
		putchar('-');
	}
	if(x>=10) write(x/10);
	putchar('0'+(x%10));
}

void dfs(int x,int y){
	if(n-x+1+y<m) return;
	if(x>n){//wh(y);
		ans++;return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;wis[x]=i;
		if(dis[x-1]>=f[i]) dfs(x+1,y);
		else dfs(x+1,y+1);
		vis[i]=0;wis[x]=0;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n),read(m);dis[0]=1;
	for(int i=1;i<=n;i++) dis[i]=dis[i-1]*i%mod;
	wh(dis[n]);return 0;
	scanf("%s",a+1);
	for(int i=1;i<=n;i++){
		if(a[i]=='1') dis[i]=0;
		else dis[i]=dis[i-1]+1;
	}
	for(int i=1;i<=n;i++) read(f[i]);
	dfs(1,0);
	wh(ans);
	return 0;
}
