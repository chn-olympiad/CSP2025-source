#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w,id;
}e[4000010];
int n,m,k,cnt,fa[100010],sum,ans=1e9,c[20],l=0,v[100010];
int Find(int x){
	return x!=fa[x]? fa[x]=Find(fa[x]):fa[x];
}
bool cmp(node a,node b){
	return a.w<b.w;
}
void solve(int x){
	int tot=l,sum=0;
	sort(e+1,e+1+cnt,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	bool flag=0;
	map<int,bool>bj;
	for(int i=1;i<=cnt;i++){
		int x=Find(e[i].u),y=Find(e[i].v);
		
		if(x!=y){
			fa[x]=y;
			tot+=e[i].w;
			sum++;
			if(!bj[e[i].id]){
				bj[e[i].id]=1;
				tot+=c[e[i].id];
			}
			if(sum>=n-1){
				flag=1;
				continue;
			}
		}
	}
	//cout<<sum<<endl;
	if(flag&&tot<ans)ans=tot;
	//cout<<ans<<endl;
}
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[++cnt]={u,v,w,0};
		e[++cnt]={v,u,w,0};
	}
	//cout<<n<<endl;
	solve(0);
	bool flag;
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i])flag=1;
		//int v;
		for(int j=1;j<=n;j++){
			scanf("%d",&v[j]);
			for(int k=1;k<j;k++){
				e[++cnt]={j,k,v[k]+v[j],i};
				e[++cnt]={k,j,v[k]+v[j],i};
			}
		}
		solve(i);
	}
	if(!flag)printf("0");
	else printf("%d",ans);
	return 0;
}
