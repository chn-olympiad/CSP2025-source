#include<bits/stdc++.h> 
using namespace std;
int a[121];
int n,m,r,s;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	if(n==2)
	{
		cin>>r>>s;
		cout<<r+s;
	}
	else
	{
		cin>>r;
		cout<<r;
	}
	return 0;
}
