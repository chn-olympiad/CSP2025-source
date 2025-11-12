#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],num,pos,c,r;
bool cmp(int a,int b){return a>b;} 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	num=a[1];
	pos=n*m;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++) 
		if(a[i]==num) 
		{
			pos=i;
			break;
		}
	c=(pos+n-1)/n;
	pos%=n;
	if(pos==0) pos=n;
	if((c%2)==1) r=pos;
	else r=n-pos+1;
	printf("%d %d\n",c,r);
	return 0;
}
