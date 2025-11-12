#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],mi[30];
bool vis[30],visk[30],visans[30];
int cnt=0;
void dfs(int num,int sum,int jian)
{
	if (num>n)
	{
		if (sum>cnt)
			cnt=sum;
		return;
	}
	if (a[num]==k)
	{
		sum++;
		memset(visans,0,sizeof visans);
		dfs(num+1,sum,0);
		dfs(num+2,sum,0);
	}
	else
	{
		memset(vis,0,sizeof vis);
		int tmp=a[num];
		for (int i=20;i>=0;i--)
			if (tmp>=mi[i])
			{
				tmp-=mi[i];
				vis[i]=1;
			}
		for (int i=20;i>=0;i--)
			if (vis[i]&&visans[i])
				visans[i]=0;
			else
				visans[i]=(visans[i]||vis[i]);
		bool sf=true;
		for (int i=20;i>=0;i--)
			if (visans[i]!=visk[i])
			{
				sf=false;
				break;
			}
		if (sf)
		{
			sum++;
			memset(visans,0,sizeof visans);
			dfs(num+1,sum,0);
			dfs(num+2,sum,0);
		}
		else
		{
			dfs(num+1,sum,jian+1);
			dfs(num+2,sum,0);
		}
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool sf1=true,sf2=true;
	cin >> n >> k;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		if (a[i]>1)
			sf1=false;
		if (a[i]==0)
			sf2=false;
	}
	if (sf1&&sf2)
	{
		cout << n/2;
		return 0;
	}
	if (sf1&&!sf2)
	{
		if (k==0)
		{
			cnt=0;
			for (int i=1;i<=n;i++)
				if (a[i]==k)
					cnt++;
				else if (a[i]==a[i+1])
				{
					cnt++;
					i++;
				}
			cout << cnt;
		}
		else
		{
			for (int i=1;i<=n;i++)
				if (k==a[i])
					cnt++;
			cout << cnt;
		}
		return 0;
	}
	mi[0]=1;
	for (int i=1;i<=20;i++)
		mi[i]=mi[i-1]*2;
	int tmp=k;
	for (int i=20;i>=0;i--)
		if (tmp>=mi[i])
		{
			tmp-=mi[i];
			visk[i]=1;
		}
	dfs(1,0,0);
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
