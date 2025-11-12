#include<bits/stdc++.h>
using namespace std;
int n,ans=0,big=0;
int a[6000];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		ans+=a[i];
		big=max(big,a[i]);
	}
	if(n<3)
	{
		cout<<"0";
	}
	else
	{
		if(ans>big*2)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
