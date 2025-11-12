#include <bits/stdc++.h>
using namespace std;
int n, m, c, r, num;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int l=n*m;
	for(int i=0;i<l;i++)scanf("%d",&a[i]);
	int R=a[0];
	sort(a,a+l);
	for(int i=l-1;i>=0;i--){
		if(a[i]==R){
			num=l-i;
			break;
		}
	}
	c=ceil(1.0*num/n);
	r=num%n;
	if(r==0){
		if(c%2==0)r=1;
		else r=n;
		printf("%d %d",c,r);
		return 0;
	}
	if(c%2==0)r=n+1-r;
	printf("%d %d",c,r);
	return 0;
} 
