#include<bits/stdc++.h>
using namespace std;
struct edge{
	long long x,y,w;
}way[2000010];
long long n,m,k,sk[10010],zhi,fa[10010],cnt,ans,c;
bool cmp(edge A,edge B){
	return A.w<B.w; 
}
long long find(long long X){
	long long xx=X;
	while(fa[X]!=X){
		X=fa[X];
	}
	fa[xx]=X;
	return X;
}
int main(){
	//冷静下来  我相信你 
	//ios别炸 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++)fa[i]=i;
	for(long long i=1;i<=m;i++){
		cin>>way[i].x>>way[i].y>>way[i].w;
	}
	for(long long i=1;i<=k;i++){
		cin>>c;
		for(long long j=1;j<=n;j++){
			cin>>sk[j];
			if(sk[j]==0){
				zhi=j;
			}
		}
		for(long long j=1;j<=n;j++){
			if(j!=zhi)way[++m].x=zhi,way[m].y=j,way[m].w=sk[j];
		}
	}
	sort(way+1,way+m+1,cmp);
	for(long long i=1;i<=m&&cnt<n-1;i++){
		long long fax=find(way[i].x),fay=find(way[i].y);
		if(fax!=fay){
			fa[fax]=fay;
			ans+=way[i].w;
			cnt++;
		}
	}
	cout<<ans;
	return 0;
}
