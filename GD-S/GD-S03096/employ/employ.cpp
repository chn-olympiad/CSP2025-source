#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

const int N=500,mod=998244353;

int n,m;
string s;
int c[N+1];

int ans=1;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);

	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		ans=(1ll*ans*i)%mod;
	}
	
	cout<<ans;
	return 0;
}

