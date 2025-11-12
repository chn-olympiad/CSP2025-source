#include<bits/stdc++.h>//30
#define int long long
using namespace std;
int n=0,m=0,ans=0;
int a[510]={0};
int p[510]={0};
signed main()
{
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=getchar()-'0';if(a[i]==0)f++;
	}
	for(int i=1;i<=n;i++)cin>>p[i];
	if(!f||!f&&m==n)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%998244353;
		}
		cout<<ans;return 0;
	}
	else cout<<"sto ¡é¡é¡ê orz";
	
	return 0;
}
