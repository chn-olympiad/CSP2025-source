#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],x,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(a[i]>=a[1]) x++;
	}
	c=x/n+(bool)(x%n);
	r=x%n?x%n:n;
	if(c%2==0) r=n-r+1;
	printf("%d %d",c,r);
	return 0;
}

