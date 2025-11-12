#include<bits/stdc++.h>
using namespace std;

int n,m,a[1010],t=1,r=1;
int main()
{
	freopen("seat.in","r",std.in)
	freopen("seat.out","w",std.out)
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	for(int j=2;j<=n*m;j++)
	{
		if(a[1]<a[j])
		{
			if(t%2!=0)
				r++;
			else
				r--;
		}
		if(t%2!=0)
		{
			if(r>m)
			{
				r--;
				t++;
			}			
		}
		else
			if(r<1)
			{
				r++;	
				t++;
			}
	}
	cout<<t<<" "<<r;
	return 0;
}
