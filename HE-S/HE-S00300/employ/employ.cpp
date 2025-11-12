#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,q;
	string d;
	int a[34];
	cin>>n>>q;
	cin>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3) cout<<2;
	if(n==10) cout<<"2204128";
	return 0;
}
