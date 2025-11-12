#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],p,q,c,r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	q=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==q){
			p=i;
			break;
		}
	c=(p-1)/n+1;
	if(c%2==0){
		if(p%n==0)r=1;
		else r=n-p%n+1;
	}
	else {
		if(p%n==0)r=n;
		else r=p%n;
	}
	printf("%d %d",c,r);
	return 0;
}
