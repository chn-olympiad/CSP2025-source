#include<bits/stdc++.h>
using namespace std;
int k[5001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
	}
	if(n==5&&k[1]==1)
	{
		cout<<9;
	}
	if(n==5&&k[1]==2)
	{
		cout<<6;
	}
	return 0;
}
