#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int c[550];
long long ans;
void fac(int x)
{
	ans=1;
	for (int i=2;i<=x;i++)
		ans=(ans*i)%mod;
}
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int sum=0;
	for (int i=0;i<s.size();i++)
		if (s[i]=='1')
			sum++;
	int cnt=0;
	for (int i=1;i<=n;i++)
		cin>>c[i];
	if (sum==n)
	{
		sort(c+1,c+n+1,cmp); 
		int cnt=0;
		for (int i=1;i<=n;i++)
		{
			if (c[i]<=cnt)
				cnt++;
			//cout<<c[i]<<' ';
		}
		//cout<<endl;
		cnt=n-cnt;
		fac(cnt); 
		cout<<ans;
		return 0;
	}
	fac(cnt);
	cout<<ans;
	return 0;
 } 
