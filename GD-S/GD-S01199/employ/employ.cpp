#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;
string s;
int a[550],b[550],d[550];
bool jz()
{
	int t=0,sum=0;
	for(int i=1; i<=n; i++)
	{
		if(s[i-1]=='0')
		{
			t++;
		}
		else
		{
			if(d[i]-t<=0) t++;
			else sum++;
		}
	}
	if(sum>=m) return true;
	else return false;
}
void js(int x)
{
	if(x==n+1)
	{
		if(jz())
		{
			ans++;
		}
		return;
	}
	for(int i=1; i<=n; i++)
	{
		if(b[i]!=1)
		{
			b[i]=1;
			d[x]=a[i];
			js(x+1);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
	}
	js(1);
	ans%=998244353;
	printf("%d",ans);
	return 0;
}
