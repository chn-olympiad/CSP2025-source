#include <bits/stdc++.h>
using namespace std;
int n,m,c,r,d;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",a+i);
	d=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
		if(a[i]==d){
			c=ceil(i*1.0/n);
			if(c%2==1) r=i-i/n*n;
			else r=n-(i-i/n*n)+1;
			break;
		}
	printf("%d %d\n",c,r);
	return 0;
}
