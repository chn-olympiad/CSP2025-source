#include <bits/stdc++.h>
using namespace std;
int a[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string h;
	cin>>h;
	for(int i=0;h[i]!='\0';i++)
	{
		int u=h[i]-'0';
		if(0<=u && 9>=u)
		{
			a[u]+=1;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int k=0;k<a[i];k++)
		{
			cout<<i;
		}
	}
	
	return 0;
}
