#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500001];
bool use[500001]; 
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	if (k==0||k==1)
		{
		for (int i=1;i<=n;i++)
			{
			cin>>a[i];
			if (a[i]==k)sum++;
			}
		cout<<sum;
		fclose(stdin);
		fclose(stdout);
		return 0;
		}
	for (int i=1;i<=n;i++)
		{
		cin>>a[i];
		if (a[i]==k&&a[i]!=0)sum++,use[i]=1;
		else use[i]=0;
		}
	for (int i=1;i<=n;i++)
		{
		if (use[i]==1)continue;
		int yes=0,ans=a[i],j;
		for (j=i+1;j<=n;j++)
			{
			if (use[j]==1)
				{
				yes=1;
				break;
				}
			ans=a[j]^ans;
			if (ans==k)
				{
				yes=2;
				break;
				}
			}
		if (yes==1)continue;
		if (yes==2)
			{
			sum++;
			for (int x=i+1;x<=j;x++)use[x]=1;
			}
		}
	for (int i=1;i<=n;i++)
		if (a[i]==k&&use[i]==0)sum++;
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
