#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+20;
const int M=1e6;
int n,m,k,c[N];
int fa[N],vis[N];
int cnt,op[N];
ll ans=1e18;
struct node{
	int x;
	int y;
	int val;
}a[M],d[M];
bool cmp(const node &x,const node &y){
	return x.val<y.val;
}
int find(int x){
	if(x==fa[x])return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
ll ask(){
	for(int i=1;i<=n+k;i++)
	fa[i]=i,vis[i]=(i<=n);
	ll sum=0;int tot=0,x,y;
	for(int i=1;i<=cnt;i++){
		if(!op[a[i].x])continue;
		x=find(a[i].x);
		y=find(a[i].y);
		if(x==y)continue;
		sum+=a[i].val;
		if(vis[x]&&vis[y])tot++;
		fa[x]=y;vis[y]+=vis[x];
		if(tot==n-1)return sum;
	}
	return 1e18;
}
void dfs(int x,ll sum){
	if(x>k){
		ans=min(ans,ask()+sum);
		return;
	}
	dfs(x+1,sum);
	op[x+n]=1;
	dfs(x+1,sum+c[x]);
	op[x+n]=0;
}
int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		d[i].x=read();
		d[i].y=read();
		d[i].val=read();
	}
	sort(d+1,d+1+m,cmp);
	for(int i=1;i<=n;i++)
	fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=find(d[i].x);
		int y=find(d[i].y);
		if(x==y)continue;
		a[++cnt]=d[i];
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			cnt++;
			a[cnt].x=i+n;
			a[cnt].y=j;
			a[cnt].val=read();
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=n;i++)
	op[i]=1;
	dfs(1,0);
	cout<<ans;
	return 0;
}
