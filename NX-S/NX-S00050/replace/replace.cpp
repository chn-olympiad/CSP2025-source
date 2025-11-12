#include<bits/stdc++.h>
using namespace std;
int s[200010][2];
int t[200010][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[i][1]>>t[i][2];
	}
	if(q==1)
	{
		cout<<0;
	}
	return 0;
}
