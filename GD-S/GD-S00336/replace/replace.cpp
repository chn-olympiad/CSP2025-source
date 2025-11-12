#include <bits/stdc++.h>
using namespace std;
int b[200005][3];
string s1[200005],s2[200005];
int main()
{
	ios::sync_with_stdio(false);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		b[i][0]=s1[i].find("b");
		b[i][1]=s1[i].size();
		b[i][2]=b[i][0]-s2[i].find("b");
	}
	//for(int i=1;i<=n;i++) cout<<b[i]
	if(n<=200)
	{
		while(q--)
		{
			string l1,l2;
			int ans=0;
			cin>>l1>>l2;
			for(int i=1;i<=n;i++)
			{
				string x=l1;
				int l=l1.find(s1[i]);
				for(int j=l;j<l+s1[i].size();j++)
					x[j]=s2[i][j-l];
				if(x==l2) ans++;
			}
			cout<<ans<<'\n';
		}
	}
	else
	{
		while(q--)
		{
			string l1,l2; int b1,b2,ans=0;
			cin>>l1>>l2;
			b1=l1.find("b"); b2=l2.find("b");
			for(int i=1;i<=n;i++)
			{
				if(b[i][2]==b1-b2)
				{
					if(b1>=b[i][0] && b[i][1]-b[i][0]<=l1.size()-b1)
						ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
}
/*
2 4
aab aba
aaab abaa
aab aba
ab ba
*/
