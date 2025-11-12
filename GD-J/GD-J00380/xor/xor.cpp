#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],b[500010],ans;
bool used[500010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=(b[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			used[i]=true;
			ans++;
			continue;
		}
		for(int j=i-1;j>=0;j--)
		{
			if((b[i]^b[j])==k)
			{
				ans++;
				used[i]=true;
				break;
			}
			if(used[j]==true)
			{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 

