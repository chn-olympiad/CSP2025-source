#include<bits/stdc++.h>
using namespace std;
struct node{
	long long u,v,w;bool flag;
}a[1000005];
bool cmp(node x,node y){
	return x.w>y.w;
}
//vector<node>q[10105];
long long n,m,k,ind[1000005],idx,ma,ned;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;ned=m+1-n;
	for(long long i=1,u,v,w;i<=m;i++){
		cin>>a[++idx].u>>a[idx].v>>a[idx].w;
		ind[a[idx].u]++,ind[a[idx].v]++,ma+=a[idx].w;
//		q[u].push_back({v,w});
//		q[v].push_back({u,w});
	}
	for(long long i=1,c;i<=k;i++){
		cin>>c;
		for(long long j=1,z;j<=n;j++){
			cin>>z;
			a[++idx].u=n+i,a[idx].v=j,a[idx].w=c+z,a[idx].flag=1;
			ind[a[idx].u]++,ind[a[idx].v]++,ma+=a[idx].w;
//			q[i+n].push_back({i,a+c});
//			q[i].push_back({i+n,a+c});
		}
	}
	sort(a+1,a+idx+1,cmp);
	for(int i=1;ned;i++){
		if((ind[a[i].u]-1)&&(ind[a[i].v]-1)){
			cout<<a[i].w<<" "<<ma<<" "<<ind[a[i].v]<<" ";
			ind[a[i].u]--,ind[a[i].v]--,ma-=a[i].w;
			if(a[i].u<=n&&a[i].v<=n)ned--;
		}
	}
	for(int i=1;i<=idx;i++){
		if(a[i].flag&&(ind[a[i].u]-1)&&(ind[a[i].v]-1)){
			cout<<a[i].w<<" "<<ind[a[i].v]<<" ";
			ind[a[i].u]--,ind[a[i].v]--,ma-=a[i].w;
		}
	}
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
} /*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
