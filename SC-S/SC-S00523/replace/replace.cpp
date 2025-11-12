#include<bits/stdc++.h>
using namespace std;
int n,q,ans=0;
string s1[200005],s2[200005],t1,t2;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	while(q--)
	{
		ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++)
		{
			int t=t1.find(s1[i]);
			if(t==-1)continue;
			for(int r=t;r+s1[i].size()<=t1.size();r++)
			{
				string t3=t1;
				for(int w=0;w<s1[i].size();w++)
				{
					if(t3[r+w]!=s1[i][w])break;
					t3[r+w]=s2[i][w];
				}
				if(t3==t2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}