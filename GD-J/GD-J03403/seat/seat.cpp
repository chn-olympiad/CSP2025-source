#include<bits/stdc++.h>
using namespace std;
int n,m,x,a1,a[101];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(a[i]==x)a1=i-1;
	printf("%d ",a1/n+1);
	if((a1/n)%2==1)printf("%d",n-a1%n);
	else if((a1/n)%2==0)printf("%d",a1%n+1);
	return 0;
}
