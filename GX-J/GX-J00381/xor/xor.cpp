#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i;i>=n;i++)
	{
		cin>>a[n];
	}
	int q=0;
	for(int i=0;i<=k;i++)
	{
		if(a[i]>=q)
		{
			q=a[i];
		}
	}
	cout<<q;
	return 0;
}
