#include<bits/stdc++.h>
#define MOD (998244353)
using namespace std;
int n,a[5005],uses,ans;
bool use[5005];
bool judge()
{
	if(uses<3) return 0;
	int sun=0,maxx=-1;
	for(int i=1;i<=n;i++)
	{
		sun+=a[i]*use[i];
		maxx=max(a[i]*use[i],maxx);
	}
	return sun>maxx*2;
}
void d(int m)
{
	if(m>=n)
	{
		ans+=judge(),
		use[m]=1,
		uses++,
		ans+=judge(),
		ans%=MOD,
		use[m]=0,
		uses--;
		return;
	}
	d(m+1);
	use[m]=1,
	uses++;
	d(m+1);
	use[m]=0,
	uses--;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	d(1);
	cout<<ans;
	return 0;
}
//