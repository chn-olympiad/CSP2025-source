#include <bits/stdc++.h>
using namespace std;
int n,q;
struct str
{
	string s1,s2;
}s[200005];
string t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].s1>>s[i].s2;
	}
	while(q--)
	{
		int cnt=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++)
		{
			if(t1.find(s[i].s1)!=string::npos && t2.find(s[i].s2)!=string::npos)
			{
				cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
    return 0;
}
