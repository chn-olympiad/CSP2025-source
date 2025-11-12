#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int ma[20][10009];
struct s{
	int w,to;
	s(int a,int b)
	{
		b=a,a=to;
	}
};
vector<s>v[1000009];




struct xy{
	int w,x,y;
};

xy dis[1000009];
int ha[1000009];

struct ss{
	int sum,p;
	ss(int a,int b)
	{
		sum=a,p=b;
	}
};

bool e[1000009];
queue<ss>q;


int cmp(xy a,xy b)
{
	return a.w>b.w;
}



signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		v[x].push_back(s(y,z));
		v[y].push_back(s(x,z));
		ans+=z;
		ha[x]++,ha[y]++;
		dis[i].w=z,dis[i].x=x,dis[i].y=y;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin>>ma[i][j];
		}
	}
	
	if(k==0)
	{
		int fl=0;
		sort(dis+1,dis+1+m,cmp);
		for(int i=1;i<=m;i++)
		{
			int x=dis[i].x;
			int y=dis[i].y;
			int w=dis[i].w;
			if(ha[x]>=2&&ha[y]>=2&&fl==0)
			{
				ans-=w;
				ha[x]--,ha[y]--;
				if(ha[x]==1||ha[y]==1) fl=1;
			}
			else if(ha[x]>2&&ha[y]>2)
			{
				ans-=w;
				ha[x]--,ha[y]--;
			}
		}	
		cout<<ans;	
	}
	
	
	return 0;
}
