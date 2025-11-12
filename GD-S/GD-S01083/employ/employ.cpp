#include<iostream>
#include<algorithm>
using namespace std;
const int mod=998244353;
int a[505],b[505];
long long ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,pot=1,cnt=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>0)cnt++;
	}
	for(int i=1;i<=cnt;i++)
	{
		ans=ans*i%mod;
	}
	cout<<ans;
	return 0;
}
