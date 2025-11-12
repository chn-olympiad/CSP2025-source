#include <bits/stdc++.h>
using namespace std;
int a[5005],gg;
int main()
{
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>gg;
	for(int i=1;i<=gg;i++)
	{
		cin>>a[i];
		if(a[i]==i) 
		{
			gg+=a[i];
		}
	}
	cout<<gg;
}
