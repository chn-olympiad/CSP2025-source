#include <bits/stdc++.h>
using namespace std;
string a[110], b[110];
int n, q;
string change(string s,int k,int j)
{
	int sz = a[k].size();
	for(int i=0;i<sz;i++)
		if(a[k][i]!=s[i+j])
			return s;
	for(int i=0;i<sz;i++)
		s[i+j] = b[k][i];
	return s;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	if(n<=100 && q<=100)
	{
		while(q--)
		{
			string s1,s2,t;
			int ans = 0;
			cin>>s1>>s2;
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j+a[i].size()<=s1.size();j++)
					if(change(s1,i,j)==s2)
						ans++;
			}
			cout<<ans<<endl;
		}
	}
	else
	{
		for(int i=1;i<=q;i++)
			cout<<0<<endl;
	}
	return 0;
}
