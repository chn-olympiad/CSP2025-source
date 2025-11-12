#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m,y;
	cin>>n>>m;
	string str;
	cin>>str;
	int a[n];
	y=n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			--y;
		}
	}
	long long x=1;
	for(int i=y;i>0;--i)
	{
		x*=i;
	}
	cout<<x<<endl;
	
	return 0;
}
