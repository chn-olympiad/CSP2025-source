#include<bits/stdc++.h>
using namespace std;

long long n,m,k,ui,bl,cnt,s;
long long wi[10005],ans;
bool b[10005];
struct xx{
	long long u,v;
	long long w;
};
xx g[1100005];
bool cmp(xx xa,xx xb){
	return xa.w<xb.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		cin>>g[i].u>>g[i].v>>g[i].w;
	}
	cnt=m;
	for(long long i=1;i<=k;i++){
		cin>>ui;
		for(long long j=1;j<=n;j++){
			cin>>wi[j];
			if(wi[j]==0) bl=j;
		}
		for(long long j=1;j<=n;j++){
			if(bl!=j){
				g[++cnt].u=bl;
				g[cnt].v=j;
				g[cnt].w=wi[j];
			}
		}
	}
	sort(g+1,g+cnt+1,cmp);
	for(long long i=1;i<=cnt;i++){
		if(!(b[g[i].u]&&b[g[i].v])){
			b[g[i].u]=b[g[i].v]=1;
			ans+=g[i].w;
			s++;
		}
		if(s==n-1)break;
	}
	cout<<ans;
	return 0;
}
