#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct road
{
	int u,v,w;
}ct[114514];
int cs[1145][1145];
int cnt[114514];
int sum;
int byd;
int temp[114514];
int ans;

bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;

	for(int i=1;i<=m;i++)

	{
		cin >> ct[i].u>>ct[i].v>>ct[i].w;
		cnt[i]=ct[i].w;

	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			cin >> cs[i][j];
		//	cout << cs[i][j] << endl;
			temp[i]=cs[i][1];
			cnt[m+i*k-k+j]=cs[i][j];
			//cout << m+i*k-k+j<<endl;
		}
	}


	sort(cnt+1,cnt+m+k*n+1,cmp);
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=m+k*n;j++)
		if(cnt[j]==temp[i])
		{
			cnt[i]=-1;
			break;
		}
	}
/*	for(int i=1;i<=m+k*n;i++)
	{
		cout << cnt[i]<<endl;
	}*/
	for(int i=1+k;i<=k+n-1;i++)
	{
		ans+=cnt[i];
	}
	cout << ans;












}

