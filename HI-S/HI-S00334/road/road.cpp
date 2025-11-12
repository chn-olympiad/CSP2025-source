#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;
struct Road{
	int x;
	int y;
	int t;
};
bool cmp(Road x,Road y)
{
	return x.t<y.t;
} 
int f[1010];
int find(int x);
int main{
	//return f[x]==x?x:(f[x]=find(f[x]));
}
{

	int n,m;
	cin>>n>>m;
	Road road[m+10];
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
		for(int i=1;i<=m;i++)
	{
		cin>>road[i].x>>road[i].y>>road[i].t;
	}
	sort(road=1,road+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int fx=find(road[i].x),fy=find(road[i].y);
		if(fx=?fy) f[fx]=fy,n--;
		if(n==1){
			cout<<road[i].t;
			return 0;
		}
	}
	cout<<-1<,endl;
	return 0;
}
