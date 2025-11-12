#include <iostream>
#include <string>
using namespace std;
int m,n,cnt=0,ans=1;
string s;
int c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>m>>n>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==1)cnt++;
	}
	if(cnt<m)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=cnt;i++)
	{
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
