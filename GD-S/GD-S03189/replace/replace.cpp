#include<bits/stdc++.h>
using namespace std;
struct node{
	string x,y,s1,s2;
}s[1000005];
int n,q;
string done(string s)
{
	string s_="";
			int index=0;
			for(int i=0;i<s.size();i++)
			{
				if(s[i]=='b')
				{
					index=i;
					break;
				}
			}
			if(s.size()/2<=index)
			{
				for(int i=s.size()-index-1;i<=index;i++)
				{
					s_.push_back(s[i]);
				}
			}
			else
			{
				for(int i=index;i<=s.size()-index-1;i++)
				{
					s_.push_back(s[i]);
				}
			}
	
	return s_;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].x>>s[i].y;
		s[i].s1=done(s[i].x);
		s[i].s2=done(s[i].y);
	}
	while(q--)
	{
		int ans=0;
		string t1="",t2="",t1_="",t2_="";
		cin>>t1>>t2;
		t1_=done(t1);
		t2_=done(t2);
		for(int i=1;i<=n;i++)
		{
			if(t1_==s[i].s1&&t2_==s[i].s2)
			{
				ans++;
			}
		}
		
		cout<<ans<<endl;
	}
		
	return 0;
}
