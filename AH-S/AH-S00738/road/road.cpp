#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct edge{
	int u,v,w;
}a;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int unit
int n,m,k,x,y,z,a[15][N],fa[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a.u=u;  a.v=v;  a.w=w;
		g.push_back(a);
		e.v=x,e.u=y;
		g.push_back(a);
	}
	sort(g+1,g+1+m,cmp);
	
	return 0;
}
/*




*/
