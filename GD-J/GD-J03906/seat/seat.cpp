#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[1052],c,b,d,g;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	g=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	if(a[i]==g){c=n*m-i+1;break;}
	b=c/m;
	d=c%m;
	if(d!=0)b++;
	if(d==0)d=m;
	if(b%2==0)d=m+1-d;
	printf("%d %d",b,d);
	return 0;
}
