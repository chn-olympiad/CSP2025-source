#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],ra,pos,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	scanf("%d",a+i);
	ra=a[1];
	sort(a+1,a+n*m+1,[](const int x,const int y){
		return x>=y;
	});
	pos=lower_bound(a+1,a+n*m+1,ra,greater<int>())-a;
	c=(pos+n-1)/n;
	if(c&1)
	r=(pos-1)%n+1;
	else
	r=n-(pos-1)%n;
	printf("%d %d",c,r);
	return 0;
}
