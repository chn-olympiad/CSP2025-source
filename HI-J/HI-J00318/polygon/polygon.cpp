#include<bits/stdc++.h>
using namespace std;
int a[4];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]+a[2]>=a[3])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 
