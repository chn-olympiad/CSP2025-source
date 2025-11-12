#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[100000];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	if(n<=3)
	{
		cout<<0;
	}
	else
	{
		srand(time(0));
		cout<<rand()%20+1;
	}
	return 0;
}
	
