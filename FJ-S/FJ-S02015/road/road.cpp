#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=0,dis[10010],pre[10010];
vector <pair <long long,long long> > a[10010];
bool ch[10010];
//bool check[10010][10010];
//map <pair <long long,long long> ,long long> t; 

struct node
{
	long long v,u,w;
	friend bool operator <(node x,node y)
	{
		return x.v<y.v;
	}
};
priority_queue <node> q; 
long long find(long long x)
{
	if(pre[x]==x) return x;
	pre[x]=find(pre[x]);
	return pre[x];
}
void Kru()
{
	ans=0;
	for(long long i=1;i<=n;i++) pre[i]=i;
	while(!q.empty())
	{
		node temp=q.top();
		long long x=temp.u,y=temp.w;
		q.pop();
		if(find(x)==find(y)) continue;
		pre[find(x)]=find(y);
		ans=ans+-1*temp.v;
	}
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
//	cout<<n<<' '<<m<<' '<<k<<endl;
	long long c,u,w,v;
	for(long long i=1;i<=m;i++)
	{
		cin>>u>>w>>v;
		a[u].push_back(make_pair(v,w));
		a[w].push_back(make_pair(v,u));
		q.push(node{-1*v,u,w});
//		if(!check[u][w])
//		{
//			t[make_pair(u,w)]=t[make_pair(w,u)]=v;
//		}
//		check[u][w]=check[w][u]=1;
//		t[make_pair(u,w)]=t[make_pair(w,u)]=min(t[make_pair(u,w)],v);
	}
	for(long long i=1;i<=k;i++)
	{
		cin>>c;
//		if(c!=0) return 114514;
//		cout<<c<<endl;
		for(long long j=1;j<=n;j++)
		{
			cin>>v;
//			cout<<v<<endl;
			if(i==j) continue;
			a[i].push_back(make_pair(v,j));
			a[j].push_back(make_pair(v,i));
			q.push(node{-1*v,i,j});
//			if(!check[i][j])
//			{
//				t[make_pair(i,j)]=t[make_pair(i,j)]=v;
//			}
//			check[i][j]=check[j][i]=1;
//			t[make_pair(i,j)]=t[make_pair(j,i)]=min(t[make_pair(i,j)],v);
		}
	}
//	cout<<"asdfsa\n";
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			if(i==j) continue;
//			q.push(node{-1*t[make_pair(i,j)],i,j});
//			cout<<i<<' '<<j<<' '<<t[make_pair(i,j)]<<endl;
//		}
//	}
	Kru();

	cout<<ans<<endl;

	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
