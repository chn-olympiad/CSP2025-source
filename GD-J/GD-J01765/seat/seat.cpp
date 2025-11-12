#include<bits/stdc++.h>
using namespace std;
int p,a[1005],n,m,loc;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int x=0,y=0;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//n行m列，输出  列,行   ，蛇形排列
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
	    cin>>a[i];}
	p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(p==a[i])
		{
			loc=i;
			break;
		}
	}
	x=ceil(loc*1.0/n);
	if(x%2)
	{
		y=loc-(x-1)*n;
	}
	else
	{
		y=n+1-(loc-(x-1)*n);
	}
	cout<<x<<" "<<y;
	
	 
	
	
	
	
	
	
	return 0;
}
