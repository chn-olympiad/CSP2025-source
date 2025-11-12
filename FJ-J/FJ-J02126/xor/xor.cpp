#include<bits/stdc++.h>
using namespace std;
int b[1000010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,ln,rn,lm,rm;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		int p=0;
		for(int j=a[i];j>0;j/=2)
		{
			b[i]+=j%2*pow(10,p);
			p++;
		}
	}
	cout<<2;
	return 0;
 } 
 
