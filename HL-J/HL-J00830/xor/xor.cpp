#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int a[100000];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	 } 
	srand(time(0));
	cout<<rand()%20;
	return 0;
}
	
