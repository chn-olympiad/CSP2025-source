#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,c=1,d;
	scanf("%d%d%d",&a,&b,&d);
	for(int i=1;i<a*b;i++)
	{
		int e;
		scanf("%d",&e);
		if(e>d) c++;
	}
	int x=c/a;
	int y=c%a;
	if(y!=0) x++;
	if(y==0) y=a;
	if(x%2==0) y=a-y+1;
	printf("%d %d",x,y);
	return 0;
}
