#include<bits/stdc++.h>
using namespace std;
int ma[10003][10003],b[10003],Min;
int n,m,k;
void DFS(int no,int fi,int mo)
{
	if(no==fi)
	{
		Min=min(Min,mo);
		return ;
	}
	if(b[no]==-1) return ;
	for(int i=1;i<=n;i++)
	{
		if(ma[no][i]>0)
		{
			b[no]=-1;
			DFS(i,fi,mo+ma[no][i]);
			b[no]=1;
		}
	}
	return ;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n >>m >>k;
	for(int i=1;i<=n;i++)
	{
		int u,v,w;
		cin >>u >>v >>w;
		ma[u][v]=w;
		ma[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		int abcdefg;
		cin >>abcdefg;
		for(int j=1;j<=n;j++) cin >>abcdefg;
	}
	int MIN=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			Min=2147483647;
			DFS(i,j,0);
			MIN=MIN+Min;
		}
	}
	cout <<MIN;
	return 0;
}
