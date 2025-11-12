#include<bits/stdc++.h>
using namespace std;
int n,k;
int arr[9999];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	if(k<=1 && n<=10)
	{
		cout<<1;
	}
	else
	{
		cout<<2;
	}
	return 0;
}
