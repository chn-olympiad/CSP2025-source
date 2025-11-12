#include<iostream>
#include<algorithm>
#define MAXN 1000005
using namespace std;
int n,m,k,a[10005],ans,sum;
struct road{
	int u,v,w;
}r[MAXN];
bool cmp(road x,road y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	sort(r+1,r+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(a[r[i].u]==1 && a[r[i].v]==1) continue;
		a[r[i].u]=1;a[r[i].v]=1;
		ans+=r[i].w;
		sum++;
		if(sum>=n-1) break;
	}
	cout<<ans;
	return 0;
}
