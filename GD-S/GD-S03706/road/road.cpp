#include<bits/stdc++.h>
using namespace std;
int in(){
	int ans=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) ans=ans*10+c-'0';
	return ans*f;
}
int n,m,k;
struct F{
	int u,v,w;
}p[2000010],q[200010],qq[200010];
bool cmp(F a,F b){
	return a.w<b.w;
}
int fa[10110];
int find(int x){
	if(x==fa[x]) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int c[20],a[20][10010],b[20][10010];
int se[20];
long long ans,tr;
void get(int x){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++) b[i][j]=a[i][j];
	}
	for(int i=1;i<=n+k;i++) fa[i]=i;
	long long pa=x,cnt=0;
	int lq=0;
	for(int i=1;i<=n-1;i++){
		int u=q[i].u,v=q[i].v;
		if(find(u)==find(v)) continue;
		int mi=q[i].w,mii=0;
		for(int j=1;j<=k;j++){
			if(!se[j]) continue;
			if(b[j][u]+b[j][v]<=mi){
				mi=b[j][u]+b[j][v];
				mii=j;
			}
		}
		if(mii){
			pa+=mi;
			if(pa>=tr||pa>=ans) return;
			b[mii][u]=0;
			b[mii][v]=0;
			fa[find(u)]=fa[find(v)]=find(mii+n);
		}
		else qq[++lq]=q[i];
	}
	for(int i=1;i<=k;i++){
		if(!se[i]) continue;
		for(int j=1;j<=n;j++){
			if(find(j)!=find(i)){
				qq[++lq]={i+n,j,b[i][j]};
			}
		}
	}
	sort(qq+1,qq+1+lq,cmp);
	for(int i=1;i<=lq;i++){
		int u=qq[i].u,v=qq[i].v;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			pa+=qq[i].w;
			fa[fv]=fu;
			if(pa>=ans) return;
		}
	}
	ans=min(ans,pa);
}
void dfs(int p,long long cost){
	if(cost>=ans) return;
	if(p>k){
		get(cost);
		return;
	}
	se[p]=1;
	dfs(p+1,cost+c[p]);
	se[p]=0;
	dfs(p+1,cost);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=in();m=in();k=in();
	for(int i=1;i<=m;i++){
		p[i].u=in();p[i].v=in();p[i].w=in();
	}
	for(int i=1;i<=k;i++){
		c[i]=in();
		for(int j=1;j<=n;j++) a[i][j]=in();
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(p+1,p+1+m,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		int u=p[i].u,v=p[i].v;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			cnt++;
			q[cnt]=p[i];
			tr+=p[i].w;
			fa[fv]=fu;
		}
		if(cnt==n-1) break;
	}
	ans=tr;
	dfs(1,0);
	cout<<ans;
	return 0;
}

