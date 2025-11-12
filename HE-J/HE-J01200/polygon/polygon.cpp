#include<bits/stdc++.h>
using namespace std;
int a[10005],n;
int main()
{
	fropen("polygon.in","r",stdin);
	fropen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>=3)
	{
		cout<<a[2]+a[3]+a[4];
	}
	
	fclose(stdin);
	fclose(stdout);
}
