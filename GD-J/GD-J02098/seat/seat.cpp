#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;scanf("%d%d",&n,&m);
	int x;scanf("%d",&x);int sum=1;
	for(int i=1,y;i<n*m;i++)
	{
		scanf("%d",&y);
		if(y>x)sum++;
	}
	int c=(sum+n-1)/n;
	int r=sum-n*(c-1);
	if(c%2==0)r=n-r+1;
	printf("%d %d\n",c,r);
	return 0;
}
