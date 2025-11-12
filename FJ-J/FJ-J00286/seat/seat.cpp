#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node { int x,idx; } a[110]; 
bool cmp(node x,node y) { return x.x>y.x; }
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i) scanf("%d",&a[i].x), a[i].idx=i;
	sort(a+1,a+1+n*m,cmp);
	int c=1,r=1;
	for(int i=1;i<=n*m;++i){
		if(a[i].idx==1) { printf("%d %d\n",c,r); return 0; }
		if(c&1) ++r; else --r;
		if(r==n+1) ++c, r=n;
		else if(r==0) ++c, r=1;
	}
	return 0;
}
