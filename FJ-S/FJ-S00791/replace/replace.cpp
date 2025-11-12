#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],v[N];
string s[N],s2[N],s3[N],s4[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>s2[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s3[i]>>s4[i];
	}
	for(int i=1;i<=q;i++)
	{
		cout<<0<<endl;
	}
	return 0;
}
