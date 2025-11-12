#include<bits/stdc++.h>
using namespace std;
const int N=1e5+200;
int T;
struct node{
	int a,b,c;
}d[N];
struct ed{
	int x,id;
};
bool cmp(node x,node y) {
	return x.a>y.a;
}
int ans,n;
void dfs(int k,int sum,int a,int b,int c) {
	if(a>n/2||b>n/2||c>n/2)return;
	if(k>n) {
		ans=max(ans,sum);
		return ; 
	}
	dfs(k+1,sum+d[k].a,a+1,b,c);
	dfs(k+1,sum+d[k].b,a,b+1,c);
	dfs(k+1,sum+d[k].c,a,b,c+1);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++){scanf("%d%d%d",&d[i].a,&d[i].b,&d[i].c);}
		if(n<=10)dfs(1,0,0,0,0);
		else {
			for(int i=1;i<=n;i++) {
				ans+=max(d[i].a,max(d[i].b,d[i].c));
			}
			printf("%d\n",ans);
		} 
		printf("%d\n",ans);
	}
	return 0;
}
