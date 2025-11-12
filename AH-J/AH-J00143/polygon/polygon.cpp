#include<bits/stdc++.h>
using namespace std;
const int X=998244353,N=5005;
int n,a[N],sum;
bool f[N];
int enedd[N],id;
int lis[N][N],di;
void dfs(int step,int ma,int lon)
{
	if(step==0)
	{
		sort(enedd+1,enedd+id+1);
		bool flag=0;
		for(int i=1;i<=di;i++)
		{
			bool F=0;
			for(int j=1;j<=id;j++)
			{
				if(enedd[j]!=lis[i][j])
				{
					F|=1;
					break;
				}
			}
			flag|=F;
		}
		if(lon>2*ma&&!flag)
		{
			sum++;
			sum%=X;
			di++;
			for(int i=1;i<=id;i++)
			{
				lis[di][i]=enedd[i];
			}
		}
		memset(enedd,0,sizeof(enedd));
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]|=1;
			id++;
			enedd[id]=a[i];
			dfs(step-1,max(ma,a[i]),lon+a[i]);
			id--;
			f[i]&=0;
			
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		dfs(i,0,0);
	}
	cout<<sum;
	return 0;
}
//AC!!!!
