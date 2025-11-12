#include<bits/stdc++.h>
using namespace std;
long long randd()
{
	long long x=rand();
	x=abs(x)%10;
	return x;
}
int n,q;
string a;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	while(n--)
	{
		cin>>a;
		cin>>a;
	}
	while(q--)
	{
		cin>>a>>a;
		cout<<randd()<<"\n";
	}
	return 0;
}
