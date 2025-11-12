#include<bits/stdc++.h>
using namespace std;
string s[200005][2],x,y;
int n,q,ans;
void bfs()
{
	queue<string> q;
	string z=x;
	for(int i=1;i<=n;i++)
	{
		if(z.find(s[i][0])<z.size())
		{
			string m=z;
			for(int j=z.find(s[i][0]),k=0;s[i][1][k];k++)
			{
				m[j+k]=s[i][1][k];
			}
			if(m==y)
			{
				ans++;
			}
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	while(q--)
	{
		cin>>x>>y;
		ans=0;
		bfs();
		cout<<ans<<endl;
	}
	return 0;
}
