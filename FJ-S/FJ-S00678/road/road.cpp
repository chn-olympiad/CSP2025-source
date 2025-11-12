#include<bits/stdc++.h>
using namespace std;
int f[10005];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
struct mode{
	int x,y,w;
}e[4000005];
bool cmp(mode x,mode y){
	return x.w<y.w;
}
long long xxx=2000000000;
int b[10005];
int main(){
	cin.tie(0)->sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,cnt=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[++cnt].x=u;
		e[cnt].y=v;
		e[cnt].w=w;
	}
	sort(e+1,e+1+cnt,cmp);
	int maxx=-1,ans=1;
	for(int i=1;i<=cnt;i++){
		int x=e[i].x,y=e[i].y;
		int fx=find(x),fy=find(y);
		if(fx==fy) continue;
		f[fx]=fy;
		ans++;
		if(ans==n){	
			cnt=i;
			maxx=e[cnt].w; 
			break;
		}
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>b[j];
			for(int k=j-1;k>=1;k--){
				if(1LL*1+c+b[j]+b[k]>xxx) continue;
				if(c+b[j]+b[k]<maxx){
					e[++cnt].w=c+b[j]+b[k];
					e[cnt].x=j;
					e[cnt].y=k;
				}
			}
		}
	}
	sort(e+1,e+1+cnt,cmp);
	int s=0;
	ans=1;
	for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<=cnt;i++){
		int x=e[i].x,y=e[i].y;
		int fx=find(x),fy=find(y);
		if(fx==fy) continue;
		f[fx]=fy;
		ans++;
		s+=e[i].w;
		if(ans==n) break;
	}
	cout<<s;
	return 0;
}
