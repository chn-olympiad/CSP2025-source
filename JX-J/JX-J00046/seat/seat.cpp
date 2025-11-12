#include<bits/stdc++.h>
using namespace std;
int cj[105];
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,a;
cin>>n>>m;
cin>>a;
cj[a]++;
for(int i=2;i<=n*m;i++)
{
	int c;
	cin>>c;
	cj[c]++;
}
int x=1,y=1,flag=0;
for(int i=100;i>=0;i--)
{
	
	if(cj[i]!=0)
	{
		if(i==a)
		{
			cout<<x<<' '<<y;
			return 0;
		}
		if(y==n&&flag==0)
		{
			 x++;
			 flag=1;
		}
		else if(y==1&&flag==1)
		{
			x++;
			flag=0;
		}
		else if(flag==0) 
		{
			y++;
		}
		else if(flag==1)
		{
			y--;
		}
		
	}
}
	return 0;
}
