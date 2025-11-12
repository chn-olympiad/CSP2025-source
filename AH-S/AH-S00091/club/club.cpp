#include<bits/stdc++.h>
using namespace std;
int n,t,f[100010];
long long s;
struct fun{int xiang,zu;}a[100010][4];
bool cmp(fun a,fun b){return a.xiang!=b.xiang?a.xiang>b.xiang:a.zu<b.zu;}
priority_queue<pair<int,pair<int,int> > > q[4];
pair<int,pair<int,int> > ch;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		cin>>n;
		s=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=1;
			cin>>a[i][1].xiang>>a[i][2].xiang>>a[i][3].xiang;
			a[i][1].zu=1,a[i][2].zu=2,a[i][3].zu=3;
			sort(a[i]+1,a[i]+1+n,cmp);
			ch.first=a[i][f[i]+1].xiang-a[i][f[i]].xiang;
			ch.second.first=a[i][f[i]].xiang;
			ch.second.second=i;
			q[a[i][f[i]].zu].push(ch);
			if(q[a[i][f[i]].zu].size()>(n/2))
			{
				int x=q[a[i][1].zu].top().second.second;
				f[x]++;
				ch.first=a[x][f[x]+1].xiang-a[x][f[x]].xiang;
				ch.second.first=a[x][f[x]].xiang;
				ch.second.second=x;
				q[a[x][f[x]].zu].push(ch);
				q[a[i][1].zu].pop();
			}
		}
		for(int i=1;i<=3;i++)
		{
			while(!q[i].empty())
			{
				s+=q[i].top().second.first;
				q[i].pop();
			}
		}
		cout<<s<<'\n';
	}
	return 0;
}
