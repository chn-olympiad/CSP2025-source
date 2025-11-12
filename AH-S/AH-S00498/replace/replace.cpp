#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6+10;
int n,q;
map<string,string> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	while(q--)
	{
		int cnt=0;
		string s1,s2;
		cin>>s1>>s2;
		if(s1.size()!=s2.size()) {cout<<"0\n";continue;}
		for(auto k: mp)
		{
			string st1=k.first,st2=k.second;
			int lenst1=st1.size(),lens2=s2.size();
			int p=s1.find(st1);
			string st="";
			if(p>=0) 
			{
				for(int i=0;i<p;i++)
					st+=s1[i];
				st+=st2;
				for(int i=p+lenst1;i<lens2;i++) st+=s1[i];
				if(st==s2) {cnt++;}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
