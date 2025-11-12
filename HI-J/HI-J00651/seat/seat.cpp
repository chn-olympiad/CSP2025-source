#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	int n,m,a[110],x = 1,y,c;
	cin>>n>>m;
	for(int i = 1; i<=n*m;i++)
	{
		cin>>a[i];
	}    
	c = a[1];        
	for(int i = 1; i<=n*m;i++)
	{
		if(a[i]>c)
		{
			c = a[i];
			y = i;
		}
	} 
	if (y>n)
	{
		x+=y%n;
		y%=n+1;
		y+=1;
		if (y>n)
		{
			y%=n;
			x++;
		}
		if(x%2 == 0)
			y++; 
	}
	cout<<x<<" "<<y;
	  
	return 0;
}
