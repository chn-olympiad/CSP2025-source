#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,w[10010],ans,mink,he[100010],q=1,kv[10010][10010],z=1000000000;
struct a{
	long long kn,knum;
}kk[1000010];
bool cmp(a x,a y){
	return x.kn<y.kn;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w[i];
		//mm[u][v]=w[i];//min(w,m[u][v]);
	//	mm[v][u]=w[i];//min(w,m[v][u]);
	}
	for(int i=1;i<=k;i++){
		cin>>kk[i].kn;
		mink=min(mink,kk[i].kn);
		kk[i].knum=i;
		for(int j=1;j<=n;j++){
			cin>>kv[q][j];
		}
		q++;
	}
	sort(w+1,w+n+1);
	for(int i=1;i<=n;i++){
		sort(kv[i]+1,kv[i]+n+1);
		he[i]=kv[i][1]+kv[i][2];
		z=min(he[i],z);
	}
	ans+=w[1]+w[2]+z+mink;
	cout<<ans;
	return 0;
}