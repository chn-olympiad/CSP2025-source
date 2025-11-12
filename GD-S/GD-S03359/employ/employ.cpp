#include<bits/stdc++.h>

using namespace std;

int n,m;
int t;
string ss;
int s[505];
int c[505];
long long ans;
const long long MOD=998244353;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>ss;
	for(int i=1;i<=n;i++)
	{
		s[i]=ss[i-1]-'0';
		
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]!=0)
		{
			t++;
		}
	}
	ans=1;
	//cout<<t<<'\n';
	for(int i=1;i<t;i++)
	{
		ans*=i;
		ans%=MOD;
	}
	cout<<ans;
} 
