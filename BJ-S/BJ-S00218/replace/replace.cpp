
#include<bits/stdc++.h>
using namespace std;
string ss1,ss2;
bool check(string a,string b)
{
	if(a.length()!=b.length())return 0;
	
	return a==b;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	pair<string,string> s[38000],t[38000];
	for(int i=1;i<=n;i++)cin>>s[i].first>>s[i].second;
	for(int i=1;i<=q;i++)cin>>t[i].first>>t[i].second;
	
	for(int i=1;i<=q;i++)
	{
		
		int ans=0,mi=9999999,ma=-1;
		int l=t[i].first.length();
		for(int u=0;u<l;u++)
		{
			if(t[i].first[u]!=t[i].second[u])
			{
				ma=max(ma,u);
				mi=min(mi,u);
				
			}
		}
		for(int u=0;u<l;u++)
		{
			for(int v=u;v<l;v++)
			{
				if(u>mi||v<ma)continue;
				
				ss1.clear();
				ss2.clear();
				for(int j=u;j<=v;j++)
				{
					ss1.push_back(t[i].first[j]);
					ss2.push_back(t[i].second[j]);
				}
					int ll=ss1.length();
					for(int k=1;k<=n;k++)
					{
						int ll1=s[k].first.length();
					
						if(ll!=ll1)continue;
						if(check(s[k].first,ss1)&&check(s[k].second,ss2)&&u<=mi&&v>=ma)ans++;
					}
				
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

