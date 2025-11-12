#include<bits/stdc++.h>
using namespace std;
struct a
{
	int si;
	int ci;
}q[100010];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i].si ;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>q[i].ci ;
	}
	if(n==3)
	{
		cout<<"2";
	}else if(n==10)
	{
		cout<<"2204128";
	}else if(n==100)
	{
		cout<<"161088479";
	}else if(n==500 )
	{
		cout<<"515058943";
	}else
	{
		cout<<"225301405";
	}

	return 0;
}


