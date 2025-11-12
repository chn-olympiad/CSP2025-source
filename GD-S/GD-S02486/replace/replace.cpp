#include <bits/stdc++.h>
#include <string>
using namespace std;
int n,m;
string a1[5000010],b1[5000010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a1[i]>>b1[i];
	}
	for(int i=1;i<=m;i++)
	{
		int ans=0;
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size())
		{
			cout<<0<<endl;
		}else
		{
			for(int j=1;j<=n;j++)
			{
				int p=a.find(a1[j]);
				if(p!=-1)
				{
					string t=a;
					t.replace(p,a1[j].size(),b1[j]);
					if(t==b)
					{
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
