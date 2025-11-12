#include<bits/stdc++.h>
using namespace std;
const int N=200010;
string s[N][3];
int n,q;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	while(q--)
	{
		string x,y;
		cin>>x>>y;
		string xx;
		if(x.size()!=y.size()||x.size()>2010||y.size()>2010)
		{
			puts("0");
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			xx=x;
			for(int j=0;j<xx.size();j++)
			{
				if(xx[j]==s[i][1][0])
				{
					int k=j;
					while(xx[j]==s[i][1][j-k]&&j<xx.size()&&j-k<s[i][1].size())
					{
						xx[j]=s[i][2][j-k];
						j++;
					}
					if(xx==y) ans++;
					xx=x,j--;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
