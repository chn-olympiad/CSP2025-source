#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,k;
bool c[10001];
long long b[10001],a[10001][10001];
struct node
{
	long long start,end,longer;
}road[10001];
void di(long long place)
{
	long long temp=0x3f3f3f3f,temp1;
	for(int i=1;i<=m;i++)
	{
		b[i]=a[place][i];
		if(temp>b[i] && !c[temp1])
		{
			temp1=i;
			temp=b[i];
		}
	}
	c[temp1]=true;
	ans+=temp;
	di(temp1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=0x3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>road[i].start>>road[i].end>>road[i].longer;
		a[road[i].start][road[i].end]=road[i].longer;
	}
	long long q,w,r,e,t;
	for(int i=1;i<=k;i++)
	{
		cin>>q>>w>>r>>e>>t;
	}//none city
	di(1);
	cout<<ans;
}
