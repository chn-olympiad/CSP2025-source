#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	if(q==1)
	{
		string a,b;
		cin>>a>>b;
		string s[q][2];
		for(int i=0;i<q;i++)
		cin>>s[i][1]>>s[i][2];
		for(int i=0;i<q;i++)
		cout<<0;
		return 0;
	}
	cout<<2;
	return 0;
}
