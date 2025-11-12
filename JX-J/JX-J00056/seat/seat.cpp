#include<bits/stdc++.h>
using namespace std;
int n,m,h,c,r,a,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&k);
	for(int i=1;i<n*m;i++){
		scanf("%d",&a);
		if(a>k)h++;
	}
	c=h/n+1;
	r=h%n+1;
	if(c%2==0)r=n-r+1;
	printf("%d %d",c,r);
	return 0;
}
