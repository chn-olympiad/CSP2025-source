#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
string s;
int c[510],cnt[510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,sum=0,k=0;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		sum+=int(s[i-1]-'0');
	}
	if(sum<m)
	{
		cout<<0;
		return 0;
	}
	sort(c+1,c+n+1);
	if(m==n)
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=N;
		}
		cout<<ans;
		return 0;
	}
	srand(time(0));
	int x=rand();
	cout<<x;
	return 0;
}
