#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define int long long
struct node{
	int id,w;
	bool operator>(node b)const&{return w>b.w;}
}a[N][4];

priority_queue<node,vector<node>,greater<node> >q[4];
int c[4];
int ans=0;
void f(int k)
{
	int i=q[k].top().id;
	c[k]--,c[k+1]++;
	ans-=q[k].top().w;
	q[k].pop();
	if(k!=2)
		q[k+1].push({i,a[i][k].w-a[i][k+1].w});
	else
		q[k+1].push({i,INT_MAX});
}

 main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1].w>>a[i][2].w>>a[i][3].w;
			a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
			for(int l=2;l<=3;l++)
				for(int j=1;j<l;j++)
					if(a[i][j].w<a[i][l].w)
					{
						int w=a[i][j].w,id=a[i][j].id;
						a[i][j].w=a[i][l].w;
						a[i][j].id=a[i][l].id;
						a[i][l].id=id;
						a[i][l].w=w;
					}
		}
		
		ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i][1].w;
//			cout<<a[i][1].w<<"\n";
			q[a[i][1].id].push({i,a[i][1].w-a[i][2].w});
			c[a[i][1].id]++;
			if(c[a[i][1].id]>n/2)
				f(a[i][1].id);
		}
		for(int i=1;i<=3;i++)
			while(!q[i].empty())
				q[i].pop(); 

		cout<<ans<<'\n';
		c[1]=c[2]=c[3]=c[4]=0;
	}
	return 0;
}
