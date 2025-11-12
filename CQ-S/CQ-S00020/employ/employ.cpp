#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;bool f=0;char ch=getchar();
	while(ch<'0'||ch>'9')f^=(ch=='-'),ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int Maxn=505;
int n,m;
int a[Maxn];
int c[Maxn];

namespace sub1{
	int ans=0;
	int vis[Maxn],p[Maxn];
	void dfs(int x){
		if(x==n+1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				int ok=(a[i]&(cnt<c[p[i]]));
				cnt+=(!ok);
			}
			ans+=(n-cnt>=m);return;
		}
		for(int i=1;i<=n;i++)if(!vis[i]){
			vis[i]=1;p[x]=i;dfs(x+1);vis[i]=0;
		}
	}
	inline void solve(){
		dfs(1);
		printf("%d\n",ans);
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)scanf("%1d",&a[i]);
	for(int i=1;i<=n;i++)c[i]=read();
	if(n<=10)sub1::solve(),exit(0);
	return 0;
}
/*
3 2
101
1 1 2
*/
