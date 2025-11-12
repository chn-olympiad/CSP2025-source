#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],fl;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	fl=a[1];
	sort(a+1,a+1+n*m);
	int p=lower_bound(a+1,a+1+n*m,fl)-a;
	printf("%d ",(n*m-p)/n+1);
	if(((n*m-p)/n+1)&1) printf("%d",(n*m-p)%n+1);
	else printf("%d",n-(n*m-p)%n);
	return 0;
}
