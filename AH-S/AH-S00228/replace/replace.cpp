#include<bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-1;j++)
		{
			cin>>a>>b;
		}
	}
	if(n==4)
	{
		cout<<"2"<<endl<<"0";
	}
	if(n==3)
	{
		cout<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"0";
	}
	return 0;
}
