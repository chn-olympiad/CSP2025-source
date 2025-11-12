#include<bits/stdc++.h>
using namespace std;

int a[105],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);int x=a[1];
	sort(a+1,a+1+n*m);int y=n*m-(lower_bound(a+1,a+1+n*m,x)-a)+1;
	int l,r;if(y%n==0) l=y/n;else l=y/n+1;
	if(l%2==1) r=(y-1)%n+1;else r=n-(y-1)%n;
	printf("%d %d",l,r);return 0;
}
