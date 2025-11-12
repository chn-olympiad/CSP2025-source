#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t,n,vis[4],sum;
struct node{
	int s[4];
	
}a[100005];
struct club
{
	int id,val;
}clb[4][100005];
int srt(int x)
{
	if(a[x].s[1] >= a[x].s[2] && a[x].s[1] >= a[x].s[3])return 1;
	if(a[x].s[2] > a[x].s[1] && a[x].s[2] > a[x].s[3])return 2;
	if(a[x].s[3] >= a[x].s[1] && a[x].s[3] >= a[x].s[2])return 3;
}
bool cmp(club a , club b)
{
	if(a.id == b.id)return a.val > b.val;
	return a.id > b.id;
}
void sol()
{
	sum = 0;
	scanf("%d",&n);
	club clb[4][100005];
	vis[1] = vis[2] = vis[3] = 0;
	for(int i = 1;i <= n;i++)
	{
		a[i].s[0] = 0x3f3f3f3f;
		for(int j = 1;j <= 3;j++)
		{
			scanf("%d",&a[i].s[j]);	
		}
		int num = srt(i);
		clb[num][++vis[num]].id = i;
		clb[num][vis[num]].val = a[i].s[num];
	}
	sort(clb[1]+1,clb[1]+vis[1]+1,cmp);
	sort(clb[2]+1,clb[2]+vis[2]+1,cmp);
	sort(clb[3]+1,clb[3]+vis[3]+1,cmp);
	for(int i = 1;i <= 3;i++)
	{
		for(int j = 1 ;j <= vis[i];j++)
		{
			if(j > n/2)break;
			sum += clb[i][j].val;
		}
	}
	for(int i = 1;i <= 3;i++)
	{
		if(vis[i] > n/2)
		{
			for(int j = vis[i] - (n/2) + 1;j <= vis[i];j++)
			{
				int num = clb[i][j].id;
				a[num].s[i] = 0;
				sort(a[num].s+1,a[clb[i][j].id].s+4);
				sum += a[num].s[3];
			}
		}
	}
	printf("%d\n",sum);
}
int main()
{
	freopen("club3.in","r",stdin);
	freopen("club3.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		sol();
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
