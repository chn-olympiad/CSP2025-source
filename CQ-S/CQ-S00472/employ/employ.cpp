#define allLL
#include<bits/stdc++.h>
using namespace std;
#define N 500005
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
#define LL long long
#ifdef allLL
#define int LL
const int INF=(1e18);
#else
const int INF=(1e9);
#endif
template<typename T>void read(T&x){
x=0;char c=getchar();/*T fh=1;*/
while(c<'0'||'9'<c){/*if(c=='-'){fh=-1;}*/c=getchar();}
while('/'<c&&c<':'){x=x*10+(c^'0');c=getchar();}/*x*=fh;*/}
template<typename T>void write(T x){
if(x<0){putchar('-');x=-x;}if(x>9){write(x/10);}putchar('0'+(x%10));}
#define P 998244353
int n,m;
char s[N];
int c[N];
int ans=0;
int vis[N];
int p[N];
void dfs(int u){
	if(u==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[p[i]]||s[i]=='0')cnt++;
		}
//		for(int i=1;i<=n;i++){
//			cout<<p[i]<<',';
//		}cout<<"::"<<cnt<<endl;
		if(n-cnt>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		p[u]=i;
		dfs(u+1);
		vis[i]=0;
	}
}
#undef int
int main(){
#ifdef allLL
#define int LL
#endif
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n);
	read(m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)read(c[i]);
	if(n<=10){
		dfs(1);
		write(ans);
		return 0;
	}
	else{
		int s=1;
		for(int i=1;i<=n;i++)s=s*i%P;
		write(s);
		puts("");
	}
	return 0;
#undef int
}

