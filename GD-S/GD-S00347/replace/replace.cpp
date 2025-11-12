#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<string,string> > a;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string st1,st2;
		cin>>st1>>st2;
		a.push_back({st1,st2});
	}
	while(m--)
	{
		string st1,st2;
		cin>>st1>>st2;
		int ans=0;
		for(int i=0;i<a.size();i++)
		{
			int tt1=st1.find(a[i].first),tt2=st2.find(a[i].second);
			if(tt1==-1 || tt2==-1) continue;
			if(tt1!=tt2) continue;
			string s1=st1.substr(0,tt1),s2=st1.substr(tt1+a[i].first.size(),st1.size()-1);
			string s12=st2.substr(0,tt2),s22=st2.substr(tt2+a[i].first.size(),st2.size()-1);
//			cout<<s1<<" "<<s2<<"   "<<s12<<" "<<s22<<endl;
			if(s1==s12 && s2==s22) ans++;
		}
		cout<<ans<<endl;
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

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
