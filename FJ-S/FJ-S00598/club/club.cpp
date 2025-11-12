#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,ans,aans;
bool A=false;
struct stu{
	int f=0,s=0,t=0;
}a[maxn];
cmp(stu x,stu y){
	return x.f>y.f;
}
int vis[205][105][105],three,T;
int dfs(int now,int one,int two){
	three=now-1-one-two;
	if(now==n+1){
		return 0;
	}
	if(vis[now][one][two]){
		return vis[now][one][two];
	}
	if(one<n/2){
		vis[now][one][two]=max(vis[now][one][two],dfs(now+1,one+1,two)+a[now].f);
	}
	if(two<n/2){
		vis[now][one][two]=max(vis[now][one][two],dfs(now+1,one,two+1)+a[now].s);
	}
	if(three<n/2){
		vis[now][one][two]=max(vis[now][one][two],dfs(now+1,one,two)+a[now].t);
	}
	return vis[now][one][two];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;A=false;
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].f,&a[i].s,&a[i].t);
			if(a[i].s!=0||a[i].t!=0)A=true;
		}
		if(!A){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i+i<=n;i++){
				ans+=a[i].f;
			}
		}
		else if(n<=200){
			ans=dfs(0,0,0);
		}
		printf("%d\n",ans);
	} 
	return 0;
}
