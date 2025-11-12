#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin)
	freopen("polygon.out","w",stdout)
	int n,s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		s++;
	}
	cout<<s;
	return 0;
}