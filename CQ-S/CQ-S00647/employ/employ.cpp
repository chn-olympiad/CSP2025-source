#include<cstdio>
#include<string>
#include<algorithm>
template<typename T>void read(T &x){
	x=0;bool f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f)x=-x;
}
void write(char x){putchar(x);}
template<typename T>void write(T x){
	if(x<0)putchar('-'),x=-x;
	char stk[24];int tot=0;
	do{stk[++tot]=x%10+48;x/=10;}while(x);
	for(;tot;)putchar(stk[tot--]);
}
template<typename T,typename ...Args>void read(T &x,Args &...args){read(x);read(args...);}
template<typename T,typename ...Args>void write(T x,Args ...args){write(x);write(args...);}
const int mod=998244353,maxn=504;int n,m,flag,b[maxn],c[maxn],ans;char a[maxn];
int dp[1<<20][20];std::basic_string<int>E[20];
void add(int &x,int y){x+=y;x>=mod&&(x-=mod);}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n,m);scanf("%s",a);
	for(int i=1;i<=n;++i)read(c[i]);
	for(int j=0;j<(1<<n);++j)E[__builtin_popcount(j)]+=j;
	dp[0][0]=1;
	for(int pp=0;pp<n;++pp)for(int j:E[pp])for(int k=0;k<=pp;++k)if(dp[j][k]){
		for(int i=1;i<=n;++i){
			if(!(j&(1<<(i-1)))){
				int flag=(a[pp]=='1'&&k<c[i]);
				add(dp[j|(1<<(i-1))][k+(flag^1)],dp[j][k]);
			}
		}
	}
	for(int k=0;k<=n;++k)if(n-k+1>=m)add(ans,dp[(1<<n)-1][k]);
	write(ans);
	return 0;
}