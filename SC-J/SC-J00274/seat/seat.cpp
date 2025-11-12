#include<bits/stdc++.h>
using namespace std;
int a[103]={0},m,n,b,c,x=1,y=1,q,flag=0,e=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	b=m*n;
	for(int i=0;i<b;i++)
	{
	    cin>>c;
		if(i==0)
	    {
	    	q=c;
		}
	    a[c]=1;
	    
	}
	for(int i=100;i>=0;i--)if(a[i]==1)
	{   
	    if(i==q)
		{
			break;
		}
		if(x==1&&e!=0)
		{
			flag=0;
			y++;
			e=0;
		}
		else if(x==m&&e!=0)
		{
			flag=1;
			y++;
			e=0;
		}
		else if(flag==0)
		{
			x++;
			e=1;
		}
		else
		{
			x--;
			e=1;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}