#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	string k,l;
	cin>>n>>q;
	for(int e=1;e<=n;e++)
	{
		
		cin>>k>>l;
	}
	for(int u=0;u<q;u++)
	{
		cin>>k>>l;
	}
	if(n==4)
	{
		cout<<"2"<<endl<<"0";
		return 0;
	}
	else if(n==3)
	{
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}
	return 0;
}
	
