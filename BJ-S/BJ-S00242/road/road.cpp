#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct A{int u,v,w;}e[2000010];

int n,m,k;
int a[12][10010];
int f[10050],b[1000010];
A g[2000010];

bool cmp(A x,A y){return x.w<y.w;}

int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}

LL kruscal(int nn,int mm){
	for(int i=1;i<=nn;i++) f[i]=i;
	sort(e+1,e+mm+1,cmp);
	LL tmp=0;
	for(int i=1;i<=mm;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v)) tmp+=w,f[find(u)]=find(v),b[i]=1;
	}
	return tmp;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>a[i][0];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	LL ans=kruscal(n,m),cnt=0;
	for(int i=1;i<=m;i++) if(b[i]) cnt++,g[cnt]=e[i];
	for(int i=1;i<(1<<k);i++){
		for(int j=1;j<=cnt;j++) e[j]=g[j];
		int now=cnt,cntt=n;LL tmp=0;
		for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				tmp+=a[j][0];cntt++;
				for(int kk=1;kk<=n;kk++) now++,e[now]=(A){cntt,kk,a[j][kk]};
			}
		}
		ans=min(ans,kruscal(cntt,now)+tmp);
	}
	cout<<ans<<"\n";
	return 0;
}
