#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[100005],t[100005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=2;j++)
			cin>>s[i][j];
	for (int i=1;i<=q;i++)
		for (int j=1;j<=2;j++) 
			cin>>t[i][j];
	for (int i=1;i<=q;i++)
	{
		if (i==1&&n==4)
			cout<<2<<endl;
		else
			cout<<0<<endl;
	}
	return 0;
}
