#include <bits/stdc++.h>
using namespace std;
int n,a[100005][3],b[100005][3],ans;
vector<pair<int,int>> de[3];
void del(int x)
{
	sort(de[x].begin(),de[x].end());
	int l=de[x].size();
	for(int i=0;i<l-n/2;i++)
		ans=ans-de[x][i].first;
}
void init()
{
	ans=0;
	de[0].clear(); de[1].clear(); de[2].clear();
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		init();
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int c=0,f=0,s=2e9;
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
				if(a[i][j]>c)
				{
					c=max(c,a[i][j]);
					f=j;
				}
			}
			ans+=c;
			for(int j=0;j<3;j++) if(j!=f) s=min(s,c-a[i][j]);
			de[f].push_back({s,i});
		}
		for(int i=0;i<3;i++)
			if(de[i].size()>n/2)
			{
				del(i);
				break;
			}
		cout<<ans<<'\n';
	}
}
