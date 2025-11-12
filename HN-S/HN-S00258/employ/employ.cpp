#include<iostream>
#include<cstdio>
using namespace std;
int n,m,c[505],st[505],si;
long long ans;
char s[505];
bool f[505];
void dfs(int u)
{
	if(u==n)
	{
		int tmp=0,cnt=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0')tmp++;
			else if(tmp>=c[st[i]])tmp++;
			else cnt++;
		}
		if(cnt>=m)ans=(ans+1)%998244353;
	}
	for(int i=0;i<n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			st[si++]=i;
			dfs(u+1);
			si--;
			f[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++)cin>>c[i];
	dfs(0);
	cout<<ans<<endl;
//	for(int i=0;i<n;i++)cout<<s[i];
	return 0;
}
