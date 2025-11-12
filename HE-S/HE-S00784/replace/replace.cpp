#include<bits/stdc++.h>
using namespace std;
string a;
string b;
int n,q;
int sum;
int main()
{
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>a;
	}
	for(int i=0;i<q;i++)
	{
		cin>>b;
	}
   int y=a.length();
	for(int i=0;i<y;i++)
	{
		if(a[i]==b[i])
		{
			sum++;
		}
	}
	cout<<sum;
}
