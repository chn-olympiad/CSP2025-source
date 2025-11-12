#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i){
		scanf("%d",&a[i]);
		if(i==1)p=a[i];
	}
	sort(a+1,a+n*m+1);
	int len=n*m-(lower_bound(a+1,a+n*m+1,p)-a)+1;
	int x=(len-1)/n+1;
	if(x&1)printf("%d %d",x,len-(x-1)*n);
	else printf("%d %d",x,x*n-len+1);
	return 0;
}
