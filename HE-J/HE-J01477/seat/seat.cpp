#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],aa[15][15],nn=0,op,po,aaa;
int dx[3]={1,-1,0};
int dy[3]={0,0,1};
bool bc=1;
int cmp(int b,int c)
{
	return b>c;

}
void dfs(int x,int y)
{
	aa[x][y]=a[nn];
	if(a[nn]==aaa)
	{
		op=x;
		po=y;
		bc=0;
		return;
	}
	nn++;
	for(int i=0;i<3;i++)
	{
		if(x+dx[i]>=0&&y+dy[i]>=0&&x+dx[i]<n&&y+dy[i]<m&&aa[x+dx[i]][y+dy[i]]==0&&bc)
		{
			dfs(x+dx[i],y+dy[i]);
		}
	}
	return;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m*n;i++)
	{
		cin>>a[i];
	}
	aaa=a[0];
	sort(a,a+m*n,cmp);
	if(a[0]==aaa)
	{
		cout<<1<<' '<<1<<'\n';
	}
	else
	{
		dfs(0,0);
		cout<<po+1<<' '<<op+1<<'\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
