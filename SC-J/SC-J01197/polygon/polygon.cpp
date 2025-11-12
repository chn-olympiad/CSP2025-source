#include<bits/stdc++.h>
using namespace std;
int n,r[10];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
	}
	if(r[1]+r[2]+r[3]>2*max(max(r[1],r[2]),r[3]))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}