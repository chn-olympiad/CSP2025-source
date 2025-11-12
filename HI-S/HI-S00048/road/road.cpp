#include"bits/stdc++.h"
using namespace std;
struct node{
	int ut,to,next,fy;
};
node a[101000];
node pre[10010];
int b[10010];
void build(int u,int v,int w)
{
	int idx;
	pre[u].ut=pre[v].to;
	pre[v].next=pre[u].ut;
	pre[idx].fy=w;
	idx++;
}
bool f,f1;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].ut>>a[i].to>>a[i].fy ;
		if(a[i].ut==a[i].to==a[i].fy==0&&f==false)
		 f1=true;
		 else f=true;
	}
	for(int i=0;i<=m;i++)
	{
		cin>>b[i];
		if(b[i]==0&&f1==true)
		f1=true;
		else f1=false;
	}
	if(f==true&&f1==true)
	cout<<0;
	return 0;
 } 
