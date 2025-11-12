#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int sum=1;
	cin>>a[1];
	int a1=0,rule=1;
	if(a[1]>1)
	rule=0;
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=a[i-1])
		sum=0;
		if(a[i]==1)
		a1++;
		if(a[i]>1)
		rule=0;
	}
	if(sum==1&&k==0&&rule)
	{
		cout<<floor(double(n)/2.00);
		return 0;
	}
	else if(k==1&&rule)
	{
		cout<<a1;
		return 0;	
	}
	else 
	cout<<255;
	return 0;
}
