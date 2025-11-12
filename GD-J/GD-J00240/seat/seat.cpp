#include<bits/stdc++.h>
using namespace std;int n,m,i,a[101],o,w,v;
main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);for(i=1;i<=n*m;i++)scanf("%d",&a[i]);o=a[1];
	sort(a+1,a+1+n*m);
	for(i=1;i<=n*m;i++)if(a[i]==o)break;i=n*m+1-i;
	w=i/n+(i%n>0);v=i%n;if(i%n==0)v=n;if(w%2==0)v=n+1-v;printf("%d %d",w,v);
}
