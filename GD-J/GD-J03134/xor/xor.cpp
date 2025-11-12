#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int num,k;
	cin>>num>>k;
	int a[num];
	for(int n=0;n<num;n++)
	{
		cin>>a[n];
	}
	int p=0,q=0;
	for(int n=0;n<num;)
	{
		p=a[n];
		for(int i=n+1;i<=num;i++)
		{
			if(p==k)
			{
				n=i;
				p=0;q++;
				break;
			}
			p=p^a[i];
		}
	}
	cout<<q;
}
