#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,num;
int a[500005];
int r=1;
long long sum[500005];
bool vis[500005];
bool check(int l,int r)
{
	return sum[r+1]^sum[l]==k;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			cnt++;
		}
		sum[i]=sum[i-1]^a[i];
	}
	bool flag=1;
	for(int i=1;i<=n;i++)//枚举每个左端点 
	{
		int l=i;
		r=l;
		while(l<=r && r<=n)
		{
			if(!check(l,r))
			{
				vis[r]=1;
				r++;
			}
			else
			{
				num++;
				flag=0;
				break;
			}
		}
		if(flag)
		{
			memset(vis,0,sizeof(vis));
		}
	}
	cout<<num;
	return 0;
}
