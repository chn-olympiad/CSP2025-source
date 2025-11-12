#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,m,cnt;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string a;
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++)
	{
		int t;
		cin>>t;
		if(t==0)
		{
			cnt++;
		}
	}
	if(n-cnt<m)
	{
		cout<<0;
		return 0;
	}
	long long ans=1;
	for(int i=1;i<=n;i++)
	{
		ans=(ans*(n-i+1))%Mod;
	}
	cout<<ans;
	return 0;
}
