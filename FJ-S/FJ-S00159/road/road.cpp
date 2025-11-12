#include<bits/stdc++.h>
using namespace std;
struct road
{
	int a,b,w;
	bool u;
}r[1000006];
int n,m,k,sun,minn=INT_MAX;
//void g(int p)
//{
//	if(sun>minn) return;
//	if(p>m) ans=sun;
//	g(p+1);
//	r[p].u=1,
//	sun+=w;
//	g(p+1);
//	r[p].u=0;
//	sun-=w;
//}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>r[i].a>>r[i].b>>r[i].w;
		ans+=r[i].w;
	}
		
//	g(1);
	cout<<ans;
	return 0;
}
//@@@    @@@@@  @@@@@
//@  @     @    @    
//@   @    @    @@@@@
//@  @     @    @    
//@@@    @@@@@  @@@@@