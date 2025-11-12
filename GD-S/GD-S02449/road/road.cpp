#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long x,y,z,mark;
	bool operator<(const edge &a)const{
		return z<a.z;
	}
}e[1100005];
long long n,m,k,ans=1e18,c[15],fa[10015];
bool vis[15];
long long find(long long x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y>>e[i].z;
		e[i].mark=0;
	}
	for(long long i=1;i<=k;i++){
		cin>>c[i];
		for(long long j=1;j<=n;j++){
			cin>>e[++m].z;
			e[m].x=i;
			e[m].y=j;
			e[m].mark=1;
		}
	}
	sort(e+1,e+m+1);
	for(long long s=0;s<(1<<k);s++){
		for(long long j=1;j<=k;j++) vis[j]=false;
		long long sum=0;
		for(long long i=1;i<=k;i++) if(s&(1<<(i-1))) sum+=c[i];
		for(long long i=1;i<=n+k;i++) fa[i]=i;
		long long tot=0,cnt=0,tow=0,u;
		for(long long i=1;i<=m;i++){
			u=e[i].x+e[i].mark*n;
			if((e[i].mark)&&((s&(1<<(e[i].x-1)))==0)) continue;
			if(find(u)!=find(e[i].y)){
				fa[fa[u]]=fa[e[i].y];
				tot++;
				cnt+=e[i].z;
				if(e[i].mark){
					if(vis[e[i].x]==false){
						vis[e[i].x]=true;
						tow++;
					}
				}
				if(tot==n+tow-1) break;
			}
		}
		ans=min(ans,cnt+sum);
	}
	cout<<ans;
	return 0;
}
