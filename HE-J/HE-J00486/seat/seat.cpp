#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[109]; 
bool cmp(int x,int y)
{
	return x>y;
}
int cnt;//考生数 
int g;
bool b=1;//判断是否已经拐弯 下一步应左右排还是上下 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cin>>a[++cnt];
	}
	g=a[1];
	sort(a+1,a+cnt+1,cmp);
	int xn=1,ym=1;
	for(int i=1;i<=cnt;i++)
	{
		if(a[i]==g)
		{
			cout<<ym<<" "<<xn;
			return 0;
		}
		if((xn==n||xn==1)&&b==0)
		{
			ym++;
			b=1;
		}
		else
		{
			b=0;
			if(ym%2==1)
				xn++;
			else
				xn--;	
		}	
	}

	return 0;
}

