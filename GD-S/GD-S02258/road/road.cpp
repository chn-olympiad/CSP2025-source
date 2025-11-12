#include<bits/stdc++.h>
using namespace std;
#define N 20005
#define M 2000005
#define LL long long
#define pb push_back
int n,m,i,j,k,r,a,b,c,p,cnt,f[N],val[15],v[15][N];
LL ans,sum,res;
struct ren{
	int a,b,c;
}d[M],g[M];
bool cmp(ren x,ren y){
	return x.c < y.c;
}
int find(int x){
	if(f[x]==x) return f[x];
	return f[x]=find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		d[++p]={a,b,c};
	}
	int flag=0;
	for(i=1;i<=k;i++){
		scanf("%d",&val[i]);
		if(val[i]) flag=1;
		for(j=1;j<=n;j++) scanf("%d",&v[i][j]);
	}
	if(!flag){
		for(i=1;i<=k;i++){
			for(j=1;j<=n;j++) d[++p]={n+i,j,v[i][j]};
		}
		for(i=1;i<=n+k;i++) f[i]=i;
		sort(d+1,d+1+p,cmp);
		for(i=1;i<=p;i++){
			a=d[i].a,b=d[i].b;
			if(find(a)==find(b)) continue;
			f[find(a)]=find(b),ans+=d[i].c;
		}
		printf("%lld\n",ans);
		return 0;
	}
	else if(k<=5){		
		ans=1e18;
		for(i=0;i<(1<<k);i++){
			int len=p,pos=0,cnt=0;
			LL ss=0;
			for(j=1;j<=len;j++) g[j]=d[j];
			for(j=1;j<=k;j++){
				if(!(i&(1<<(j-1)))) continue;
				++pos,ss+=val[j];
				for(r=1;r<=n;r++) g[++len]={n+pos,r,v[j][r]};
			}
			for(j=1;j<=n+pos;j++) f[j]=j;
			res=0;
			sort(g+1,g+1+len,cmp);
			for(j=1;j<=len;j++){
				a=g[j].a,b=g[j].b;
				if(find(a)==find(b)) continue;
				f[find(a)]=find(b);
				res+=g[j].c,cnt++;
				if(cnt==n+pos-1) break;
			}
			ans=min(ans,res+ss);
		}
		printf("%lld\n",ans);
		return 0;
	}
	sort(d+1,d+1+p,cmp);
	for(i=1;i<=n;i++) f[i]=i;
	for(i=1;i<=p;i++){
		a=d[i].a,b=d[i].b;
		if(find(a)==find(b)) continue;
		f[find(a)]=find(b),ans+=d[i].c;
	}
	for(i=1;i<=k;i++){
		cnt=0,res=0,sum+=val[i];
		for(j=1;j<=n+i;j++) f[j]=j;
		for(j=1;j<=n;j++) d[++p]={n+i,j,v[i][j]};
		sort(d+1,d+1+p,cmp);
		for(j=1;j<=p;j++){
			a=d[j].a,b=d[j].b;
			if(find(a)==find(b)) continue;
			f[find(a)]=find(b),res+=d[j].c,cnt++;
			if(cnt==n+i-1) break;
		}
		ans=min(ans,res+sum);
	}
	printf("%lld\n",ans);
	return 0;
}
