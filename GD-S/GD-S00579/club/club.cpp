#include <bits/stdc++.h>
#define ll long long
#define FRE 
using namespace std;
int read(){
	int t1=0,t2=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-')t2=-1;
		c=getchar();
	}while(c>='0' && c<='9')t1=t1*10+c-'0',c=getchar();
	return t1*t2;
}
const int N=100050,INF=2147483647;
int n,ans=0,a[N],b[N],c[N];
bool cmp(int a,int b){
	return a>b;
}
void dfs(int x,int q,int w,int e,int now){
	ans=max(ans,now);
	if(x>n)return;
	if(q<n/2)dfs(x+1,q+1,w,e,now+a[x]);
	if(w<n/2)dfs(x+1,q,w+1,e,now+b[x]);
	if(e<n/2)dfs(x+1,q,w,e+1,now+c[x]);
}
int main(){
	#ifdef FRE
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	#endif
	int T;T=read();
	while(T--){
		memset(a,0,sizeof a);ans=0;
		n=read();
		for(int i=1;i<=n;i++){a[i]=read();b[i]=read();c[i]=read();}
		bool flag1=1,flag2=1;
		for(int i=1;i<=n;i++){
			if(b[i]!=0)flag1=0;
			if(c[i]!=0)flag2=0;
		}
		if(flag1&&flag2){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++)ans+=a[i];
			printf("%lld\n",ans);
			continue;
		}
		dfs(1,0,0,0,0);
		printf("%lld\n",ans);
	}
	return 0;
}
