#include <bits/stdc++.h>
using namespace std ;

int n,m,k,f[100010],xx,yy ;
struct node {
	int u,v,w ;
}   r[1000010] ;  

bool cmp(node a,node b){
	return a.w<b.w ;
}
int main () {
	freopen ("road.in","r",stdin) ;
	freopen ("road.out","w",stdout) ;
	cin>>n>>m>>k ;
	for (int i=1;i<=n;i++) {
		f[i]=i ;
	}
	for (int i=1;i<=m;i++) {
		cin>>r[i].u>>r[i].v>>r[i].w ;
		sort (r+1,r+1+m,cmp)
	}
	cout<<n<<endl ;
	return 0 ;
}
