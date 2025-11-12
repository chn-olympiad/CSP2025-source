#include<bits/stdc++.h>
using namespace std;
int a[500];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++)
	{
		cin>>a[i];
	}
	int XR=a[1],pm;
	sort(a+1,a+x+1);
	for(int i=x;i>=1;i--)
	{
		if(a[i]==XR)
		{
			pm=x-i+1;
			break;
		}
	}
	int hang,lie;
	if(pm%n==0)
	{
		hang=pm/n;
		if(hang%2==1)
		{
			lie=m;
		}
		else
		{
			lie=1;
		}
	}
	else
	{
		hang=pm/n+1;
		if(hang%2==1)
		{
			lie=pm%n;
		}
		else
		{
			lie=m-pm%n+1;
		}
	}
	cout<<hang<<" "<<lie;
	return 0;
}
