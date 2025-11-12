#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	long long he=0;
	int t=0;
	for(int i=1;i<=n;i++)
	{
		int f;
		cin>>f;
		he+=f;
		t=max(t,f);
	}
	if(he>2*t)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}