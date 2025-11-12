#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010],s[500010];
int ans;
int id;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=id+1;j<=i;j++)
		{
			if((s[i]^s[j-1])==k)
			{
				ans++;
				id=i;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}