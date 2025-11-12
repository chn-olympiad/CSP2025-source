#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,a[1000],x,y,d=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	x=1,y=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==t)
		{printf("%d %d",x,y);return 0;}
		if(y+d>n)d=-1,x++;
		else if(y+d<1)d=1,x++;
		else y+=d;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
