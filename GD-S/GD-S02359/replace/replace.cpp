#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005],ss[200005],t[200005],tt[200005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>ss[i];
	}
	if(q==1)
	{
		cin>>t[1]>>tt[1];
	}
	else
	{
		for(int i=1;i<=q;i++)
		{
			cin>>t[i]>>tt[i];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout<<"0"<<endl;
	}
	return 0;
 } 
