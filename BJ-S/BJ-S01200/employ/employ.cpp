#include <iostream>
using namespace std;
int c[502];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int cnt=n;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
		if (c[i]==0) cnt--;
	}
	int ans=1;
	for (int i=1;i<=cnt;i++)
	{
		ans=1ll*ans*i%998244353;
		
	}
	cout<<ans;
}