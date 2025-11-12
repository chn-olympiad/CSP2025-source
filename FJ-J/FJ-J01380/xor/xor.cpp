#include <bits/stdc++.h>
using namespace std;
int n,k,ans;
long long a[500005],rs;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k||rs==k||(k==0&&a[i]==a[i-1]&&a[i]))
		{
			ans++;
			rs=0;
		}
		else
		{
			rs=rs^a[i];
		}
	}
	cout<<ans;
	return 0;
}
