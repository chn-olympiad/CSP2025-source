#include <bits/stdc++.h>
#define pa pair <int,int>
#define int long long
#define y second
#define x first
using namespace std;
const int N=2e5+10;

inline int read(){
	int ans=0;bool f=0;char c=getchar();
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) ans=(ans<<1)+(ans<<3)+(c^48),c=getchar();
	return (f?-ans:ans);
}

inline void write(int x,string s=""){
	if(x<0) x=-x,putchar('-');
	static char a[50],k=0;
	do{a[short(++k)]=x%10,x/=10;}while(x);
	while(k) putchar(a[short(k--)]|48);
	if(s=="\n") putchar('\n'); else if(s==" ") putchar(' ');
}

int n,k,a[N],ans,g[N];

bool check(int cnt){
	for(int i=1;i<=cnt;++i) if(g[i]!=k) return false;
	return true;
}

void dfs(int s,int cnt){
	if(s>n){
		if(check(cnt)) ans=max(ans,cnt);
		return ;
	}
	g[cnt+1]^=a[s];
	dfs(s+1,cnt+1);
	g[cnt+1]^=a[s];
	for(int i=0;i<=cnt;++i){
		g[i]^=a[s];
		dfs(s+1,cnt);
		g[i]^=a[s];
	}
}

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;++i) a[i]=read();
	dfs(1,0);
	write(ans,"\n");
	return 0;
}
