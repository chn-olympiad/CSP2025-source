#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000005],ans;
bool v[1000005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=2)
	{
		if(n==1)
		{
			if(a[1]==k)cout<<1;
			else cout<<0;
		}else
		{
			if(a[1]^a[2]==k)
			{
				cout<<1;
			}else
			{
				cout<<0;
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			bool flag=1;
			int cnt=0;
			for(int w=j;w<j+i&&w<=n;w++)
			{
				if(v[w])
				{
					flag=0;
					break;
				}
				cnt=cnt^a[w];
			}
			if(cnt==k&&flag)
			{
				ans++;
				for(int w=j;w<j+i;w++)
				{
					v[w]=1;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
