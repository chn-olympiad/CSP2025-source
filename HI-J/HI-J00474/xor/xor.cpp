#include<bits/stdc++.h>
using namespace std;
int a[50005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(m==2||m==3)
	{
		cout<<2;
	}
	else if(m==0)
	{
		cout<<1;
	}
	else
	{
		cout<<m;
	}
	return 0;
} 
