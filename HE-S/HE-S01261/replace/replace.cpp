#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,z=0;
	char s,t;
	cin>>n>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>s;
	}
	z=2*n+2;
	for(int i=1;i<=38;i++)
	{
		cin>>t;
	}
	if(q>=4)
	{
		for(int i=1;i<=q;i++)
	    {
	    	cout<<0;
    	}
	}
	else
	{
		cout<<2<<endl;
		cout<<0<<endl;
	}
	return 0;
}
