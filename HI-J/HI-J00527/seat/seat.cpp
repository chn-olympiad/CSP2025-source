#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=n*m;
	int a[s];
	for(int i=0;i<s;i++)
	{
		  cin>>a[i];
	}
	int c=1,r=1;
	for(int i=0;i<s;i++)
	{
		if(a[0]<a[i])
		{
			if(r<m) r++;
			if(r>m) 
			{
				c++;
				r=1;
		    }
		}	
	}
	cout<<c<<" "<<r;
	return 0;
} 
