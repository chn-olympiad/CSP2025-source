#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	if(n==1)
	{
		int t,k;
		cin>>k>>t;
		if(t==k)
		{
			cout<<"1";
			return 0;
		}else
		{
			cout<<"0";
			return 0;
		}
	}else
	{
		if(n==2)
		{
			int t1,t2,k;
			cin>>k>>t1>>t2;
			cout<<max((t1|t2==k),((t1==k)+(t2==k)));
			return 0;
		}
	}
	return 0;
}