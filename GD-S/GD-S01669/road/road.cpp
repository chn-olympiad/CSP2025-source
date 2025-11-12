#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
long long n,m,k,u0,v0,w0,c,a[N],ans;
long long v[N][N];
bool az;
struct Point{
	long long w,x,y;
};
vector<Point> vec;
vector<long long> vis[N];
map<long long,long long> ma;
bool cmp(Point x,Point y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u0,&v0,&w0);
		if(v[u0][v0]!=0) v[u0][v0]=min(v[u0][v0],w0),v[v0][u0]=min(v[v0][u0],w0);
		else v[u0][v0]=w0,v[v0][u0]=w0;
	}
	for(int QAQ=1;QAQ<=k;QAQ++)
	{
		scanf("%lld",&c);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				long long w1=a[i]+a[j]+c;
				if(v[i][j]==0) v[i][j]=w1,v[j][i]=w1;
				else v[i][j]=min(v[i][j],w1),v[j][i]=min(v[j][i],w1);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			Point now;
			now.w=v[i][j];
			now.x=i;
			now.y=j;
			vec.push_back(now);
		}
	}
	sort(vec.begin(),vec.end(),cmp);
	for(int i=0;i<vec.size();i++)
	{
		ma.clear();
		az=false;
		if(!vis[vec[i].x].empty())
		{
			for(int j=0;j<vis[vec[i].x].size();j++)
				ma[vis[vec[i].x][j]]=1;
			if(!vis[vec[i].y].empty())
			{
				for(int j=0;j<vis[vec[i].y].size();j++)
				{
					if(ma[vis[vec[i].x][j]]==1) 
					{
						az=true;
						break;
					}
				}
			}
		}
		if(az) continue;
		ans+=vec[i].w;
		vis[vec[i].x].push_back(vec[i].y);
		vis[vec[i].y].push_back(vec[i].x);
	}
	cout<<ans;
	return 0;
}
