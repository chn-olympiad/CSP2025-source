#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[100005];
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int cnt=0;
	if(a[1]==k)
	{
		cnt++;
	}
	if(n==2)
if(a[1]^a[2]==k)
	{
		cnt++;
	}
	if(n==2)
	 if(a[2]==k)
	{
		cnt++;
	}
cout<<cnt;
}
