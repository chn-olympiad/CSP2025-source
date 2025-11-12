#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string> str;
string s[200001];
string hs(string x,int w,string y)
{
	string t=x;
	for(int i=0;i<y.size();i++)
	t[i+w]=y[i];
	
	return t;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		str[a]=b;
		s[i]=a;
	}
	while(q--)
	{
		string x,y;
		cin>>x>>y;
		queue<string> q;
		set<string> p;
		q.push(x);
		p.insert(x);
		int cnt;
		while(!q.empty())
		{
			string t=q.front();
			q.pop();
			for(int i=1;i<=n;i++)
			{
				int w=t.find(s[i]);
				if(w==-1)
				continue;
				string nw=hs(t,w,str[s[i]]);
				if(nw==y)
				{
					cnt++;
					continue;
				}
				if(p.count(nw))
				continue;
				else
				{
					p.insert(nw);
					q.push(nw);
				}
			}
		}
		printf("%d\n",cnt);
	}
}
