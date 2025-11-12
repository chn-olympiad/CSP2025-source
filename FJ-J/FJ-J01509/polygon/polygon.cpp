#include<iostream>
using namespace std;

int n;
int a[1000];
int sum=0;
int mx=-10;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	if(sum>mx*2)
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
