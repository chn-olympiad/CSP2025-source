#include<bits/stdc++.h>
using namespace std;
int n,m,a[1100],f[1100],w,b[1100];
string st;
const long long mod=998244353;
long long ans;
void work(int x)
{
	if(x>n)
	{
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		bool fl=0;
		if(f[i])continue;
		f[i]=1;
		if(st[x-1]=='0'||a[i]<=w)
		{
			w++;
			fl=1;
		}
		if(w>n-m)
		{
			f[i]=0;
			if(fl)w--;
			return;
		}
		work(x+1);
		f[i]=0;
		if(fl)w--;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>st;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int fl=0;
	for(int i=1;i<=n;i++)if(st[i-1]=='0')fl=1;
	if(!fl)
	{
		int p=0,q=0,l=1;
		for(int i=1;i<=n;i++)
		{
			if(!a[i])p++;
			f[a[i]]++;
		}
		long long s=1;
		while(f[l]==0)l++;
		cout<<s;
		return 0;
	}
	work(1);
	cout<<ans;
	return 0;
}
/*
4 2
1111
1 1 0 0
*/
