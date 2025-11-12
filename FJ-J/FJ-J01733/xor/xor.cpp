#include<bits/stdc++.h>
using namespace std;
int a[1000005]; 
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,f=1,x=0,f1=1;
	cin>>n>>k; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)f=0;
		if(a[i]!=1&&a[i]!=0)f1=0;
		if(a[i]==1)x++;
	}
	if(k==0&&f)
	{
		cout<<n%2;
		return 0;
	}
	if(f1)
	{
		cout<<x;
		return 0;
	}
	
	return 0;
}

