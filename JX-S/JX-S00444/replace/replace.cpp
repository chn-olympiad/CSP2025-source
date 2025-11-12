#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=5e6+10;
int n,q,ans;
struct node{
	string s1,s2;
}s[N];
string t1,t2;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i].s1>>s[i].s2;
	while(q--)
	{
		int ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){cout<<0<<endl;continue;}
		for(int i=1;i<=n;i++)
		{
			if(t1.find(s[i].s1)<=M)
			{
				int be=t1.find(s[i].s1);
				bool f=0;
				for(int j=0;j<be;j++)
					if(t2[j]!=t1[j]){f=1;break;}
				if(f==1)continue;
				for(int j=be;j<be+(int)s[i].s2.size();j++)
					if(t2[j]!=s[i].s2[j-be]){f=1;break;}
				if(f==1)continue;
				for(int j=be+(int)s[i].s1.size();j<(int)t2.size();j++)
					if(t2[j]!=t1[j]){f=1;break;}
				if(f==1)continue;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
 
