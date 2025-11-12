//GZ-S00418 贵阳市第十八中学 谷佳鸿
#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int maxn=2e4+117,maxm=2e6+5;
int n,m,k,c[15],a[15][maxn],fa[maxn],cnt,belong[15],tot,su,totn,totm;
long long ans,fans=1e18;
struct node{
	int u,v,w;
}e1[maxm],e2[maxm];
bool cmp(node a,node b){
	return a.w<b.w;
}int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}void join(int a,int b){
	int p=find(a),q=find(b);
	if(p!=q)fa[p]=q;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool flag=0;
	scanf("%d%d%d",&n,&m,&k);
	su=n+k+1;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e1[i]={u,v,w};
	}for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		flag=flag||c[i];
		bool flag1=1;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)flag1=0;
		}flag=flag||flag1;
	}
	if(k==0){
		for(int i=1;i<=n;i++)fa[i]=i;
		sort(e1+1,e1+m+1,cmp);
		for(int i=1;i<=m;i++){
			int u=e1[i].u,v=e1[i].v,w=e1[i].w;
			if(find(u)!=find(v)){
				ans+=w;
				join(u,v);
				cnt++;
			}if(cnt==n-1)break;
		}printf("%lld",ans);
		return 0;
	}if(flag==0){
		//合并 
		tot=m;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==0)belong[i]=j;
			}
		}for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				if(belong[i]==j)continue;
				e1[++tot]={belong[i],j,a[i][j]};
			}
		}
		//最小生成树 
		for(int i=1;i<=n;i++)fa[i]=i;
		sort(e1+1,e1+tot+1,cmp);
		for(int i=1;i<=tot;i++){
			int u=e1[i].u,v=e1[i].v,w=e1[i].w;
			if(find(u)!=find(v)){
				ans+=w;
				join(u,v);
				cnt++;
			}if(cnt==n-1)break;
		}printf("%lld",ans);
		return 0;
	}
	int mak=(1<<k)-1;
	for(int x=0;x<=mak;x++){
		for(int i=1;i<=m;i++){
			e2[i]=e1[i];
		}
		totn=n,totm=m;ans=0;cnt=0;
		for(int i=1;i<=k;i++){
		//新增 
			if((x>>(i-1))&1){
				totn++;
				ans+=c[i];
				if(ans>fans)continue;
				for(int j=1;j<=n;j++){
					e2[++totm]={totn,j,a[i][j]};
				}
			}
		}
		//最小生成树 
		for(int i=1;i<=su;i++)fa[i]=i;
		sort(e2+1,e2+totm+1,cmp);
		for(int i=1;i<=totm;i++){
			int u=e2[i].u,v=e2[i].v,w=e2[i].w;
			if(find(u)!=find(v)){
				ans+=w;
				if(ans>fans)break;
				join(u,v);
				cnt++;
			}if(cnt==totn)break;
		}fans=min(fans,ans);
	}printf("%lld\n",fans);
	return 0;
}

