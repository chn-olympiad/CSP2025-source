#include<bits/stdc++.h>
using namespace std;
const int MN=1e5+6;
long long n,m,k,p;
long long u,v,w,c[MN],a[106][MN];
struct node{
	long long l[106]={0},q[106];
	bool pd[106]={};
}lj[MN];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		lj[u].l[++lj[u].l[0]]=v;
		lj[v].l[++lj[v].l[0]]=u;
		lj[u].q[v]=w;
		lj[v].q[u]=w;
		p+=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<n+2;j++){
			cin>>a[i][j];
		}
	}
	cout<<w;
	return 0;
}
