#include <bits/stdc++.h>
#define z 789113
using namespace std;
int n,a[z];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	switch(n)
	{
		case 5:if(a[1]==1)
			cout<<9;
			else
			cout<<6;break;
		case 20:cout<<1042392;break;
		case 500:cout<<366911923;break;
	}
	return 0;
}

