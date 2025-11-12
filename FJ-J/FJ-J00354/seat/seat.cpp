#include<bits/stdc++.h>
using namespace std;
int a[10001]={0};
int main()
{

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int num=a[1];
//	cout<<num<<endl;
	sort(a+1,a+1+n*m);
//	for(int i=n*m;i>=1;i--)cout<<a[i]<<" ";
	int grade=0;
	for(int i=n*m;a[i]>=num;i--)
	{
//		cout<<"i= "<<i<<" "<<a[i]<<endl;
		grade++;
	}
//	cout<<grade;
//	cout<<"grade="<<grade<<endl;
	int x=1,y=1,d=1,step=1;
	while(step!=grade)
	{
		step++;
		if(d==1&&y+1<=n)
		{
			y++;
			if(y+1>n)d=3;
		}
		else if(d==3)
		{
			x++;
			d=2;	
		}
		else if(d==4)
		{
			x++;
			d=1;
		 } 
		else if(d==2&&y-1>=1)
		{
			y--;
			if(y-1<1)d=4;
		}
//		cout<<"x="<<x<<" y="<<y<<endl; 
	}
	cout<<x<<" "<<y;
	return 0;
 } 
