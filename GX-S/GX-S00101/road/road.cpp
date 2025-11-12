#include<bits/stdc++.h>
using namespace std;
struct edge{int x,y,l;}a[1000010];
int father[1000010],s[1000010],n,m,k,ans=0x7fffffff,l,vis[11],x[11][1000010];
int find(int x){
	if(father[x]==x)return father[x];
	return father[x]=find(father[x]);
}
void unionn(int x,int y){
	int fx=find(x);int fy=find(y);
	father[fy]=fx;
}
bool cmp(edge xxx,edge yyy){return xxx.l<yyy.l;}
void check(int xq){
	edge b[10000010];
	int z=0;
	for(int i=1;i<=n+xq;i++)father[i]=i;
	for(int i=1;i<=l;i++)b[i].x=a[i].x,b[i].y=a[i].y,b[i].l=a[i].l;
	for(int i=1;i<=k;i++)
		if(vis[i])
		{
			z+=s[i];
			for(int j=1;j<=n;j++){b[++l].x=n+i;b[l].y=j;b[l].l=x[i][j];}
		}
	int nans=0;
	sort(b+1,b+l+1,cmp);
	int kkk=0,flagg=0;
	for(int i=1;i<=l;i++){
		if(find(b[i].x)!=find(b[i].y)){
			unionn(b[i].x,b[i].y);
			nans+=b[i].l;
			kkk++;
		}
		if(kkk==n+xq-1){
			break;
		}
	}
	if(flagg==1)ans=min(ans,nans+z);
	l-=xq*n;
}
void dfs(int kk,int xq){
	if(kk>k)check(xq);
	else{
		vis[kk]=1;
		dfs(kk+1,xq+1);
		vis[kk]=0;
		dfs(kk+1,xq);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)father[i]=i;
	for(int i=1;i<=m;i++){cin>>a[++l].x>>a[l].y>>a[l].l;}
	for(int i=1;i<=k;i++)
	{
		cin>>s[i];
		for(int j=1;j<=n;j++)cin>>x[i][j];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
