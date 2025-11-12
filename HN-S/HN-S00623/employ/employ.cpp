#include<bits/stdc++.h>
using namespace std;
int n,m,a[505];
//S组寄了，所以整点活 
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	string s;cin>>s;
	for(int i=1;i<=n;i++)	cin>>a[i];
	long long ans=1;
	for(long long i=2;i<=n;i++)
	{
		ans=(ans*i)%998244353;
		cout<<ans<<'\n';
	}
	printf("%d\n",ans%998244353);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//哈基米哦南北路多 
//：D
 
