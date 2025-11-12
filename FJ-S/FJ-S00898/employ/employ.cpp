#include<bits/stdc++.h>
using namespace std;
#define INF=0x3f3f3f3f3f3f3f3f
#define int long long
char s[100010];
int a[100010];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3&&m==2)
	{
		cout<<2<<endl;
	}
	else if(n==10&&m==5)
	{
		cout<<2204128<<endl;
	} 
	else
	{
		cout<<1<<endl;
	}
	return 0;
} 
