#include<bits/stdc++.h>
using namespace std;
int n,m,myseat=1,myscore,x;
int a[15][15];
void fun(int x,int y,int step)
{
	myseat--;
	if(myseat==0)
	{
		cout<<x<<" "<<y;
		return ;
	}
	if(y==n&&step==1)fun(x+1,y,2);
	else if(y==1&&step==2)fun(x+1,y,1);
	else 
	{
		if(step==1)fun(x,y+1,1);
		if(step==2)fun(x,y-1,2);
	}
	return ;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>myscore;
	for(int i=1;i<=n*m-1;i++)
	{
		cin>>x;
		if(x>myscore)myseat++;
	}
	fun(1,1,1);
	return 0;
}
