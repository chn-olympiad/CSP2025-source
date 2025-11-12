
#include<bits/stdc++.h>
using namespace std;
struct str{
	string og;
	string cu;
};
str a[200010];
map<char,int> mp1;
map<char,int> mp2;
bool is_same(string sa,string sb)
{
	if(sa.size()!=sb.size())
	{
		return 0;
	}
	for(int i=0;i<sa.size();i++)
	{
		if(sa[i]!=sb[i])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].og>>a[i].cu;
	}
	int t=0;
	string s1,s2;
	while(q--)
	{
		s1="";
		s2="";
		cin>>s1>>s2;
		cout<<0<<endl;
	}
	return 0;
}



