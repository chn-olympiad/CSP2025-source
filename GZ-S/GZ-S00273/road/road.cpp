//GZ-S00273
//¹óÑôÒ»ÖÐ Ñî¾ûº­
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+100,M=1e6+10;
int n,m,k,c[20],a[20][N],f[N],cnt;
ll ans,op=1;
struct bian{
	int uu,vv,ww;
}ee[M],e[N<<4],e2[N<<4];
bool cmp(bian q,bian p){
	return q.ww<p.ww;
}
int fsb(int x){
	return f[x]==x?x:f[x]=fsb(f[x]);
}
void merge(int x,int y){
	x=fsb(x),y=fsb(y);
	f[x]=y;
}
void dfs(int x,ll res){
	if(res>=ans)	return ;
	if(x==k+1){
		for(int i=1;i<=cnt;i++)	e2[i]=e[i];
		for(int i=1;i<=n+k;i++)	f[i]=i;
		sort(e2+1,e2+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			int u=e2[i].uu,v=e2[i].vv,w=e2[i].ww;
			if(fsb(u)==fsb(v))	continue;
			res+=op*w;
			//cout<<u<<" "<<v<<" "<<w<<" "<<res<<endl;
			if(res>=ans)	return ;
			merge(u,v);
		}
		//for(int i=1;i<=k;i++)	cout<<vis[i]<<" ";
		//cout<<":"<<res<<endl;
		ans=min(ans,res);
		return ;
	}
	dfs(x+1,res);
	for(int i=1;i<=n;i++)	e[++cnt]={n+x,i,a[x][i]};
	dfs(x+1,res+op*c[x]);
	cnt-=n;
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)	f[i]=i;
	for(int i=1;i<=m;i++)
		scanf("%d %d %d",&ee[i].uu,&ee[i].vv,&ee[i].ww);
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)	scanf("%d",&a[i][j]);
	}
	sort(ee+1,ee+1+m,cmp);
	for(int i=1;i<=m;i++){
		int u=ee[i].uu,v=ee[i].vv,w=ee[i].ww;
		if(fsb(u)==fsb(v))	continue;
		ans+=op*w;
		e[++cnt]=ee[i];
		merge(u,v);
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}

//#include<bits/stdc++.h>
//using namespace std;
//const int N=1e4+100,M=1e6+10;
//int n,m,k,ans,c[20],a[20][N],f[N],sum[20],s1,s2,tot,head[N];
//struct bian{
//	int uu,vv,ww;
//}ee[M];
//struct qp{
//	int to,ne,val,xk;
//}e[N<<2];
//void add(int u,int v,int w){
//	e[++tot]={v,head[u],w,0};
//	head[u]=tot;
//}
//bool cmp(bian q,bian p){
//	return q.ww<p.ww;
//}
//void dfs(int u,int fa,int nk,bool op){
//	int res1=0,res2=0;
//	if(!op)	res2+=a[nk][u];
//	for(int i=head[u];i;i=e[i].ne){
//		int v=e[i].to,w=e[i].val;
//		if(v==fa)	continue;
//		if(a[nk][v]<=w)	res2+=a[nk][v],res1+=w;
//	}
//	if(res1>=res2){
//		s1+=res1,s2+=res2;
//		for(int i=head[u];i;i=e[i].ne){
//			int v=e[i].to,w=e[i].val;
//			if(v==fa)	continue;
//			if(a[nk][v]<=w)
//				dfs(v,u,nk,1);
//			else	dfs(v,u,nk,0);
//		}
//	}
//}
//void dfss(int u,int fa,int nk,bool op){
//	int res1=0,res2=0;
//	if(!op)	res2+=a[nk][u];
//	for(int i=head[u];i;i=e[i].ne){
//		int v=e[i].to,w=e[i].val;
//		if(v==fa)	continue;
//		if(a[nk][v]<=w)	res2+=a[nk][v],res1+=w;
//	}
//	if(res1>=res2){
//		for(int i=head[u];i;i=e[i].ne){
//			int v=e[i].to,w=e[i].val;
//			if(v==fa)	continue;
//			if(a[nk][v]<=w){
//				e[i].val=a[nk][v];
//				sum[e[i].xk]--;
//				if(!sum[e[i].xk] && e[i].xk)	ans-=(c[e[i].xk]+a[e[i].xk][1]);
//				e[i].xk=nk;
//				sum[nk]++;
//				dfss(v,u,nk,1);
//			}
//			else	dfss(v,u,nk,0);
//		}
//	}
//}
//int fsb(int x){
//	return f[x]==x?x:f[x]=fsb(f[x]);
//}
//void merge(int x,int y){
//	x=fsb(x),y=fsb(y);
//	f[x]=y;
//}
//int main(){
//	freopen("road4.in","r",stdin);
//	cin>>n>>m>>k;
//	for(int i=1;i<=n;i++)	f[i]=i;
//	for(int i=1;i<=m;i++)
//		cin>>ee[i].uu>>ee[i].vv>>ee[i].ww;
//	for(int i=1;i<=k;i++){
//		cin>>c[i];
//		for(int j=1;j<=n;j++)	cin>>a[i][j];
//	}
//	sort(ee+1,ee+1+m,cmp);
//	cout<<"sort"<<endl;
//	for(int i=1;i<=m;i++){
//		int u=ee[i].uu,v=ee[i].vv,w=ee[i].ww;
//		if(fsb(u)==fsb(v))	continue;
//		ans+=w;
//		merge(u,v);
//		add(u,v,w);
//		add(v,u,w);
//	}
//	cout<<ans<<endl;
//	for(int i=1;i<=k;i++){
//		s1=0;
//		s2=c[i];
//		dfs(1,0,i,0);
//		if(s1>=s2){
//			dfss(1,0,i,0);
//			ans-=s1;
//			ans+=s2;
//		}
//	}
//	cout<<ans;
//	return 0;
//}

