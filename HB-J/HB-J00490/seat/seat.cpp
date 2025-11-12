#include <bits/stdc++.h>
using namespace std;
const int N=15;
const int M=15;
int a[N*M];
int n,m;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int sum;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;//hang lie
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==sum)
		{
			cout<<y<<" "<<x;
			break;
		}
		if(y%2==0)
		{
			x--;
		}
		else
		{
			x++;
		}
		
		
		if(x>n)
		{
			x-=1;
			y+=1;
		}
		else if(x<1 && y%2!=0)
		{
			x-=1;
			y+=1;
		}
		else if(x<1 && y%2==0)
		{
			x+=1;
			y+=1;
		}
	}
	//ya li wo di er ti ye xie wan le,but I cant understand t3 clearly, what can i do?
	//qwq
	return 0;
}


