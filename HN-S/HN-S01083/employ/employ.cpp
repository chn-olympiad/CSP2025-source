#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
int n,m;
string s;
int da[505],t=0;
struct num{
	int id,c;
}a[505];
int ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=s.size();i++)
	{
		da[i]=s[i]-'0';
		if(da[i]=0)t++;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i].c);
		a[i].id=i;
	}
	if(t==0)
	{
		ans=1;
		for(int i=1;i<=m;i++)
		{
			ans=ans*(n-i+1)%mod;
		}
	}
	printf("%d",ans);
	return 0;
}
