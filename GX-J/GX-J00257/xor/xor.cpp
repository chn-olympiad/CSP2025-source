#include<bits/stdc++.h>
using namespace std;
int main()
{	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,arr[10000]={0},a=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
	cin>>arr[i];
	a=a+arr[i];
	}
	if(k=0)
	{
	cout<<"1";
	retutn 0;
	}
	else
	{
		int z=a/2;
		cout<<z;
	}
	
	
	
	return 0;
}
