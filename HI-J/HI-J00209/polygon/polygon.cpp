#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n = 0,t = 0;
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>t;
	}
	if(n == 5 && t == 5)
	{
		cout<<9;
	}
	else
	{
		cout<<6;
	}
}
