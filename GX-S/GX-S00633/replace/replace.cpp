#include<bits/stdc++.h>
using namespace std;
struct th
{
	string a, b;
}h[200001];
string sa,sb,x,z;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i].a>>h[i].b;
		
	}
	while(q--)
	{
		cin>>sa>>sb;
        long long ans=0;
		for(int i=1;i<=n;i++)
		{
			 x=sa.substr(0,sa.find(h[i].a));
			 z=sa.substr(sa.find(h[i].a)+h[i].a.size(),sa.size());
			if(x+h[i].b+z==sb) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
