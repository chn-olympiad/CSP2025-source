#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[200005],b[200005],c,d;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=m;i++)
	{
		int ans=0;
		cin>>c>>d;
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<=int(c.size())-int(a[j].size());k++)
			{
				string t="",tt="",ttt="";
				bool p=0;
				for(int o=0;o<int(a[j].size());o++)
				{
					if(c[o+k]!=a[j][o])
					{
						p=1;
						break;
					}
					t+=c[o+k];
				}
				if(p)continue;
				t=b[j];
				for(int o=0;o<k;o++)tt+=c[o];
				for(int o=k+int(a[j].size());o<int(c.size());o++)ttt+=c[o];
				string yggpls=tt+t+ttt;
				ans+=(yggpls==d);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}