#include<bits/stdc++.h>
using namespace std;
int arr[5005];
int n;
int pre[5005];
int v[5005];
int num,maxx;
void dfs(int x,int k)
{
	if(x>k)
	{
		int temp=0;
		int maxn=0;
		for(int i=1;i<=k;i++)
		{
			temp+=pre[i];
			maxn=max(maxn,pre[i]);
		}
		if(temp>maxn*2)
		{
			num++;
		}
		return; 
	}
	for(int i=1;i<=maxx;i++)
	{
		if(v[i]>0&&i>=pre[x-1])
		{
			v[i]--;
			pre[x]=i;
			dfs(x+1,k);
			v[i]++;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		v[arr[i]]++;
		maxx=max(maxx,arr[i]);
	}
	for(int i=3;i<=n;i++)
	{
		dfs(1,i);
	}
	cout<<num;
	return 0;
}

