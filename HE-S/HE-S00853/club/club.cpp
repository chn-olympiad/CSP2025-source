#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100010][4],b[4],n,t;
unordered_map<int,bool> m;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		m.clear();
		cin>>n;
		int su=0,x=0;
		b[0]=b[1]=b[2]=b[3]=0;
		for(int i=1;i<=n;i++)
		{
			int ma=-1;
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
				if(a[i][j]>ma)
				{
					ma=a[i][j];
					a[i][0]=j;
				}
			}
			b[a[i][0]]++;
			su+=ma;
			if(b[a[i][0]]>b[x])x=a[i][0];
		}
		priority_queue<pair<int,int> > q;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(j!=x and a[i][0]==x)
				{
					q.push({a[i][j]-a[i][x],i});
				}
			}
		}
		int tot=0;
		for(;tot<b[x]-n/2;)
		{
			if(m[q.top().second])
			{
				q.pop();
				continue;
			}
			m[q.top().second]=1;
			tot++;
			su+=q.top().first;
			q.pop();
		}
		cout<<su<<'\n';
	}
}
