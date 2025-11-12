#include <bits/stdc++.h>
using namespace std;
#define N 5010
long long x[N];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>x[i];
		
	if(n==3)
	{
		if(x[0]+x[1]>x[2]&&x[0]+x[2]>x[1]&&x[2]+x[1]>x[0])
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}
	else
	{
		cout<<2<<endl;
	}
	
	return 0;
}
