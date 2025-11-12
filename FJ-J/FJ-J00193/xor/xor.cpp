#include<iostream>
#include<cstdio>
using namespace std;
int n,k,ans;
int a[500005],b[500005];
int dfs(int x,int y)
{
	if(x>y)
		return 0;
	int cnt=0;
	bool f = true;
	if(a[x]==k)
	{
		f=false;
		cnt++;
		cnt+=dfs(x+1,y);
	}
	else
	{
		for(int i = x+1;i<=y;i++)
		{
			int z=b[i]^b[x-1];
			if(z==k)
			{
				if(dfs(x+1,i)==0)
					cnt++;
				else
					cnt+=dfs(x+1,i);
				cnt+=dfs(i+1,y);
				break;
			}
		}
		if(f)
			return dfs(x+1,y);
		return cnt;
	}
	
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
		b[i]=b[i-1]^=a[i];
	}
	if(k==1)
	{
		for(int i = 1;i<=n;i++)
		{
			if(a[i]==1)
				ans++;
		}
		cout << ans;
	}
	else
		cout << dfs(1,n);
	return 0;
}
