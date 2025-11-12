#include<bits/stdc++.h>
using namespace std;
int a[500010],b,n,c=1;
int main()
{
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	cin>>n;
	for( int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	for (int i=3;i<=n;i++)
	{
		b+=c;
		c++;
	}
	cout<<b;
	return 0;
	fclose(stdin);fclose(stdout);
}
