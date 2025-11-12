#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c=1,r=1,a[101];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i>=2)
		{
			if(a[1]<a[i])
			{
				if(c%2==1)
				{
					r+=1;
				}
				else if(c%2==0)
				{
					r-=1;
				}
				
				if(r>n || r<1)
				{
					c+=1;
					if(r>n) 
						r-=1;
					if(r<1) 
						r+=1;
				}	
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
