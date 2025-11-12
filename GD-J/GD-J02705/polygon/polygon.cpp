#include<iostream>
using namespace std;
int const maxn=100;
int main()
{
	int n;
	cin>>n;
    	int a[maxn];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int o=0,all=0,big=a[1];
	for(int i=1;i<=n;i++)
	{
		all=all+a[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]>=a[i-1])
		{
			big=a[i];
		}
 	}
	for(int i=1;i<=n;i++)
	{
		if(all>big){
			o++;
		}
	}
	cout<<o;
	return 0;
}
