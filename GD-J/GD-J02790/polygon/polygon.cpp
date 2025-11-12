#include<bits/stdc++.h>
using namespace std;
#define in(s1) freopen(s1,"r",stdin);
#define out(s1) freopen(s1,"w",stdout);
#define pii pair<int,int>
template<typename T>
inline void read(T &x){
	x=0;
	char c=getchar();
	int f=1;
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+(c-'0');
		c=getchar();
	}
	x*=f;
}
template<typename T>
inline void write(T x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
const int N=5001;
const int mod=998244353;
int ans;
int n,a[N];
bool f[N],pd;
void dfs(int x,int maxx,int sum,int lst){
	if(x>3&&sum>maxx*2)ans=(ans+1)%mod;
	if(x>n)return ;
	for(int i=lst+1;i<=n;i++)
		dfs(x+1,max(maxx,a[i]),sum+a[i],i);
}
int c[N][N];
void init(){
	c[0][0]=1;
	for(int i=1;i<=5000;i++)
		for(int j=0;j<=i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
}
int dp[N][N];
int main(){
	in("polygon.in")
	out("polygon.out")
	init();
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(a[i]!=1)pd=1;
	}
	if(pd){
		dfs(1,0,0,0);
		write(ans);
	}
	else{
		for(int i=3;i<=n;i++)ans+=c[n][i],ans%=mod;
		write(ans);
	}
	return 0;
}

