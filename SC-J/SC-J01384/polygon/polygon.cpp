#include<bits/stdc++.h>
#define int long long 
#define fast register int
using namespace std;
const int maxn=5e3+5;

int n,a[maxn],ans;

void dfs(int sum,int ma,int now){
	if(now==n+1){
		if(sum>2*ma){
			ans++;
		} 
		return ;
	}
	dfs(sum,ma,now+1);
	dfs(sum+a[now],max(a[now],ma),now+1);
}

inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}

inline void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(fast i=1;i<=n;i++){
		a[i]=read();
	}
	dfs(0,0,1);
	write(ans);
	return 0;
}