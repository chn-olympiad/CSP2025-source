#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int N=1e5+5;
int n,m;
struct node {
	int num,x;
}a[N];
bool cmp (node whx1,node whx2){
	return whx1.x>whx2.x;
}
int main(){
	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);
	scanf ("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++){
		scanf ("%d",&a[i].x);
		a[i].num=i;
	}
	sort (a+1,a+n*m+1,cmp);
	int l;
	for (int i=1;i<=n*m;i++)
		if (a[i].num==1) {
			l=i;
			break;
		}
	int c=1,r;
	while (l>n){
		l-=n;
		c++;
	}
	if (c&1) r=l;
	else r=n-l+1;
	printf ("%d %d",c,r);
	return 0;
}
