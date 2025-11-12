#include<bits/stdc++.h>
using namespace std;
int n,m,a[109],x,pos;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	x=a[1];sort(a+1,a+n*m+1);reverse(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)if(a[i]==x)pos=i-1;
	printf("%d ",pos/n+1);
	if(pos%(2*n)<n)printf("%d\n",pos%(2*n)+1);
	else printf("%d\n",2*n-pos%(2*n));
}