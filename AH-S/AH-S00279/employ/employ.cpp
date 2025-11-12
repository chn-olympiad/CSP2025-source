#include <bits/stdc++.h>
using namespace std;
const long long L=988244353;
int a[606];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	int cnt;
	cin>>n>>m;
	cnt=n;
	string s;
	cin>>s;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)cnt--;
	}
	if(cnt<m) cout<<0<<endl;
	else
	{
		long long ans=1;
		for (int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=L;
		}
		cout<<ans<<endl;
	}
	return 0;
}
