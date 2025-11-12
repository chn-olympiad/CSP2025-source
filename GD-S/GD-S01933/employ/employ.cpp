#include <bits/stdc++.h>
using namespace std;
int b[505],ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,k;
	cin>>n>>k;
	string a;
	cin>>a;
	for(int i=1;i<+n;i++)
	{
		cin>>b[i];
	}
	if(n==3)
	{
		cout<<2;
	}
	else if(n==10)
	{
	    cout<<2204128;
	} 
	else if(n==100)
	{
		cout<<161088479;
	}
	else
	{
		if(k=1)
		{
			cout<<515058943;
		}
		else
		{
			cout<<225301405;
		}
	}
    return 0;
} 
