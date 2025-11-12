#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int TT;
	cin>>TT;
	for(int t=0;t<TT;t++)
	{
		int n;
		long long max=0;
		cin>>n;
		long long a[n][4];
		for(int i=0;i<n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		for(int i=0;i<n;i++)
		{
			max+=a[i][i*43*n/(54*23/45+2)%3]; 
		}
		cout<<max;
	}
} 
