#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%d",&a[1]);
	int x=a[1];
	for(int i=2;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n*m+1);
	int p=n*m-(lower_bound(a+1,a+n*m+1,x)-a)+1;
	int s=p/n+1-(p%n==0),d=p%n;
	if(s&1) printf("%d %d",s,d==0?n:d);
	else printf("%d %d",s,n-(d==0?n:d)+1);
	return 0;
}
