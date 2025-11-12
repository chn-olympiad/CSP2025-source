#include<bits/stdc++.h>
using namespace std;
int n,m,sum,ans,cnt=1,h=1,l=1;
int a[150];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	sum=n*m;
	scanf("%d",&a[1]);
	ans=a[1];
	for(int i=2;i<=sum;++i)	scanf("%d",&a[i]);
	sort(a+1,a+sum+1,cmp); 
	while(a[cnt]>ans)
	{
		if(l%2==1)
		{
			if(h+1>n)	l++;
			else h++;
			++cnt;
		}
		
		else
		{
			if(h-1<1)	l++;
			else h--;	
			++cnt;
		}
	}
	printf("%d %d\n",l,h);
	return 0; 
}