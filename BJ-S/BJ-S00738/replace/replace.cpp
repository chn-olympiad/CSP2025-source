#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s1[N],s2[N];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--)
	{
		string x,y;
		int ans=0;
		cin>>x>>y;
		if(x.size()!=y.size())
		{
			cout<<ans<<endl;
			continue;
		}
		string xx=x;
		for(int i=1;i<=n;i++)
		{
			int sz1=x.size(),sz2=s1[i].size();
			for(int j=0;j<=sz1-sz2;j++)
			{
				for(int k=0;k<sz2;k++)
				{
					if(x[j+k]!=s1[i][k]) break;
					if(k==sz2-1)
					{
						for(int p=j;p<j+sz2;p++) x[p]=s2[i][p-j];
						if(x==y) ans++;
						x=xx;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
