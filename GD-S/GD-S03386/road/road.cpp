#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+9;
const int maxm=2e6+9;
struct node{
	int v,w;
	node(int x,int y){
		v=x;w=y;
	}
};
struct nodd{
	int u,v,num;
	long long w;
	nodd(int x,int y,long long z,int a){
		u=x;v=y;w=z;num=a;
	}
	nodd(){u=v=w=num=0;}
	bool operator <(const nodd &b)const{return w<b.w;}
}sid[maxm];
int n,m,k,tot,c[19],a[19][maxn],o[19],fa[maxn];
long long ans=-1;
int find(int x){
	if(fa[x]==x)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void dfs(int x,long long cnt,int sum){
	if(x==k+1){
		for(int i=1;i<=n+k;i++)fa[i]=i;
		long long cn=0;
		for(long long i=1,j=1;i<n+sum;j++){
			if(sid[j].num==0||o[sid[j].num]==1){
				if(find(sid[j].u)==find(sid[j].v))continue;
				fa[find(sid[j].u)]=find(sid[j].v);
				i++;
				cn+=sid[j].w;
			}
		}
		if(ans==-1)ans=cn+cnt;
		else ans=min(ans,cn+cnt);
		return;
	}
	dfs(x+1,cnt,sum); 
	o[x]=1;
	dfs(x+1,cnt+c[x],sum+1);
	o[x]=0;
}
priority_queue<nodd>p;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	long long u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		sid[++tot]=nodd(u,v,w,0);
		p.push(nodd(u,v,w,0));
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			sid[++tot]=nodd(i+n,j,a[i][j],i);
		}
	}
	sort(sid+1,sid+1+tot);
	dfs(1,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
