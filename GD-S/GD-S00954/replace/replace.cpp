#include<bits/stdc++.h>
using namespace std;

const int N=5e6+10;

struct node
{
	string a,b;
}t[N];

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>t[i].a>>t[i].b;
	string s1,s2;
	while(q--)
	{
		cin>>s1>>s2;
		int ans=0,len=s1.size();
		if(len!=s2.size())
		{
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			int d=s1.find(t[i].a);
			if(d!=-1)
			{
				int l=t[i].a.size();
				string x=s1.substr(0,d),z=s1.substr(d+l,len-l-d);
				if(x+t[i].b+z==s2)
					ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
