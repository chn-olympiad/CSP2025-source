#include<bits/stdc++.h>
using namespace std;
int n,m;
//substr
vector<pair<string,string> > vc[126];
int f(string s1,string s2)
{
	int ret=0;
	if(s1.size()!=s2.size())return 0;
	for(int i=0;i<s1.size();i++)
	{
		int c=s1[i];
		for(int j=0;j<vc[c].size();j++)
		{
			if(vc[c][j].first.size()>s1.size()-i)continue;
			if(s1.substr(i,vc[c][j].first.size())==vc[c][j].first)
			{
//				cout<<"jinru  ";
				string s3;
				s3+=s1.substr(0,i);
				s3+=vc[c][j].second;
				int u=i+vc[c][j].first.size()-1;
				s3+=s1.substr(u+1,s1.size()-u-1);
				if(s2==s3)ret++;
//				cout<<s3<<"\n";
			}
			
		}
		if(s1[i]!=s2[i])return ret;
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		string a,b;
		cin>>a>>b;
		vc[a[0]].push_back({a,b});
	}
	for(int i=0;i<m;i++)
	{
		string a,b;
		cin>>a>>b;
		cout<<f(a,b)<<"\n";
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
