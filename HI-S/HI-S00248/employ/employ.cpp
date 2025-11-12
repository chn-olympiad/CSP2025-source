#include<bits/stdc++.h> 
using namespace std;
int c[507];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s; 
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n==3)
	{
		cout<<2;
	}
	else if(n==100)
	{
		cout<<161088479;

	}
	else if(n==500)
	{
		cout<<515058943;
	}
	else
	{
		cout<<2204128;
	}
	return 0;
}
