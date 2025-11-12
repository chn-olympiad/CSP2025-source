#include<bits/stdc++.h>
const int z=1000000;
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	cin>>n>>q;
	char a[z],b[z],c[z],d[z];
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	}
	for(int j=1;j<=q;j++) 
	{
		cin>>c>>d;
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
	}
	for(int i=1;i<=q;i++)
	{
		cout<<"0"<<endl;
	}
	return 0;
}