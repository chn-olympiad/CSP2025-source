#include<bits/stdc++.h>
using namespace std;
int n,m,t[101][3]={},c=1,r=1;//c为列，r为行 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		int x;
		cin>>x;
		if(i==1)
			t[x][2]++;
		t[x][1]++;
	}
	for(int i=100;i>=0;i--)
	{
		
		if(t[i][2]==1)
		{
			cout<<c<<' '<<r;
			return 0;
		}
		if(t[i][1]!=0)
		{
			if(c%2!=0)
				r++;
			else
				r--;
		}
		if(r==n+1||r==0)
		{
			c+=1;
			if(c%2==0)
				r=n;
			else
				r=1;	
		}
			
	}	
	return 0;
 } 
