#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005],t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			cout<<0;
			continue;
		}
		int l=0;
		for(int i=1;i<=n;i++)
		{
			int t=t1.find(s1[i]);
			if(t==-1) continue;
			string x=t1.substr(0,t)+s2[i]+t1.substr(t+s1[i].size(),t1.size()-t-s1[i].size());
			if(x==t2) l++;
		}
		cout<<l<<endl;
	}
	return 0;
}

