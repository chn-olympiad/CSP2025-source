#include<bits/stdc++.h>
using namespace std;
int n,k,c;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(x==k)
		c++;
	}
	cout<<c<<'\n';
	return 0;
}
