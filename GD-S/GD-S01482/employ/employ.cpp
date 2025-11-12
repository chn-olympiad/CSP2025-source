#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s[505],c[505],t,p[505];
string str;
struct man
{
	int id,c;
};
bool check()
{
	int x=0;
	for(int i=1;i<=n;i++)
		if(i-1-x<c[p[i]]&&s[i]==1)x++;
	return x>=m;
}
int fac(int x)
{
	if(x<=1)return 1;
	return (x%998244353*fac(x-1)%998244353)%998244353;
}
int C(int a,int b)
{
	int sum=1;
	for(int i=a;i>b;i--)
		sum*=i,sum%=998244353;
	sum=(sum%998244353/fac(a-b)%998244353)%998244353;
	return sum;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool flag=true;
	cin>>n>>m>>str;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=0;i<str.size();i++)
	{
		s[++t]=(int)(str[i])-48;
		if(s[t]==0)flag=false;
	}
	if(flag)
	{
		int ans=0,x=0;
		for(int i=1;i<=n;i++)
			if(c[i]!=0)x++;
		for(int i=m;i<=x;i++)
			ans+=C(x,i);
		cout<<ans;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		p[i]=i;
	do
	{
		if(check())
			ans++;
		ans%=998244353;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}

