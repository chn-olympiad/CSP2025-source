#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,sum=0,res=0;
	cin>>n;
	int li[n];
	for (int i=0;i<n;i++)
	{
		cin>>li[i];
		sum+=li[i];
	}

//	for (int i=0;i<n;i++)
//	{
//		cout<<li[i];
//	}

	int maxx=-999;
	for (int i=0;i<3;i++)
	{
		maxx=max(maxx,li[i]);
	}
	if (sum>maxx*2)
	{
		res++;
	}
	cout<<res;
	
	return 0;
}
