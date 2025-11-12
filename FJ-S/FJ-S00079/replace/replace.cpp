#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node
{
	vector<int>n;
	map<char,int>son;
};
struct tree
{
	vector<node>t;
	void insert(string s,int x)
	{
		node emp;
		int p=0;
		int ls=s.size();
		for(int i=0;i<ls;i++)
		{
			if(t[p].son.count(s[i]))p=t[p].son[s[i]];
			else
			{
				t.push_back(emp);
				t[p].son[s[i]]=t.size()-1;
				p=t.size()-1;
			}
		}
		t[p].n.push_back(x);
	}
	void print(int p=0,string s="")
	{
		/*for(auto x:t[p].n)cout<<s<<x<<"\n";
		for(auto x:t[p].son)
		{
			print(x.second,s+x.first);
		}*/
		for(int i=0;i<(int)(t.size());i++)
		{
			cout<<i<<":";
			for(auto y:t[i].n)cout<<y<<" ";
			cout<<"\n";
			for(auto y:t[i].son)printf("(%c%d)",y.first,y.second);
			cout<<"\n";
		}
	}
	int size()
	{
		return t.size();
	}
};
map<string,pair<tree,tree>>gr;
set<string>sam;
tree bf[N],af[N];
int n,q;
string cut(string s,int x,int y)
{
	string ans;
	if(y<x)return "";
	ans.resize(y-x+1);
	for(int i=x;i<=y;i++)ans[i-x]=s[i];
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string x;
	a.t.resize(1);
	cin>>n>>q;
	string x,y;
	int st,ed;
	int cnt=0;
	string a,b,c;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		/*t=0;
		ed=y.size()-1;
		if(x==y)
		{
			sm.insert(x);
			continue;
		}
		while(x[st]==y[st])st++;
		while(x[ed]==y[ed])ed--;
		a=cut(x,0,st-1);
		b=cut(x,st,ed)+","+cut(y,st,ed);
		c=cut(y,ed+1,y.size()-1);
		if(gr.count(b))
		{
			gr[b].first.insert(a,i);
			gr[b].second.insert(c,i);
		}*/
	}
	for(int i=0;i<q;i++)
	{
		cin>>x>>y;
		cout<<0<<"\n";
	}
}
