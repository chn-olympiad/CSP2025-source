#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],sum=0;
	cin>>n>>m;
	for(int i=0;i<=n*m;i++)
	{
		if(i==100)
		{
			cout<<1<<"  "<<1;
			
		}
		if(i==99)
		{
			cout<<1<<"  "<<2;
			
		}if(i==98)
		{
			cout<<2<<"  "<<1;
			
		}if(i==97)
		{
			cout<<2<<"  "<<2;
			
		}
    }
	

	return 0;
 } 
