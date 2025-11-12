#include <bits/stdc++.h>
using namespace std;
main(){
	//feropen("number.in","r",stdin);
	//feropen("number.out","w",stdout);
	int x,y;
	cin>>x>>y;
	int a[x*y];
	for(int i=0;i<=x*y;i++)
	{
		cin>>a[i];
	}
	int z=a[0];
	for(int j=0;j<=x*y;j++)
	{	if (a[j]<a[j+1])
		{
			cout<<a[j+1]<<" "; 
		}
	}
	return 0;
}
