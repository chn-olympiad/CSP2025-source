#include<bits/stdc++.h>
using namespace std;
struct uvw{
	long u,v,w;
};
uvw u[1000010];
int mid;
long n,m,k,c[12],a[12][1000010];
long long s;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i].u>>u[i].v>>u[i].w;
		if(u[i].u<u[i].v){
			mid=u[i].u;
			u[i].u=u[i].v;
			u[i].v=mid;
		}
	}
	
	return 0;
}
