#include<bits/stdc++.h>
using namespace std;
#define int long long
int num[10010];
int cnt[110][110];
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	int l;
	for(int i=1;i<=n*m;i++)
	{
		int x;
		cin>>x;
		num[i]=x;
		if(i==1)
		{
			l=x;
		}
	}
	sort(num+1,num+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(l==num[i])
		{
			l=i;
		}
		num[i]=i;
	}
	int idx=1;
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				cnt[i][j]=idx;
				if(idx==l)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				idx++;
			}
		}
		if(j%2==0)
		{
			for(int i=n;i>=1;i--)
			{
				cnt[i][j]=idx;
				if(idx==l)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				idx++;
			}
		}
	}
	

	return 0;
}

