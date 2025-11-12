#include<bits/stdc++.h>
using namespace std;
int t,n,ans,f;
bool vis[500005];
struct id{
	int a,b,c,cha;
}xue[100005];
bool cmp(id a,id b){
	return a.cha<b.cha;
}
void dfs(int k,int sum,int q1,int q2,int q3){
	if(q1*2>n||q2*2>n||q3*2>n) return ;
	bool z=1;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		z=0,vis[i]=1;
		dfs(i,sum+xue[i].a,q1+1,q2,q3);
		dfs(i,sum+xue[i].b,q1,q2+1,q3);
		dfs(i,sum+xue[i].c,q1,q2,q3+1);
		vis[i]=0;
	}
	if(z) ans=max(ans,sum);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		f=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&xue[i].a,&xue[i].b,&xue[i].c);
			xue[i].cha=xue[i].a-xue[i].b;
			if(xue[i].c>0) f=0; 
		}
		if(f){
			sort(xue+1,xue+1+n,cmp);
			for(int i=1;2*i<=n;i++){
				ans+=xue[i].b+xue[i+n/2].a;
			}
		}else{
			dfs(0,0,0,0,0);
		}
		printf("%d\n",ans);
		ans=0;
	}
	return 0;
}
