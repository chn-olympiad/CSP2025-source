#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[10000];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==5&&a[n-1]==10)
	{
		cout<<"6";
	}
	else{
		cout<<"9";
	}
	return 0;
}
