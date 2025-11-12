#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],q[500005],t[500005],now,ans;
map <long long,int> ma;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >>n>>k;
	ma[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin >>a[i];
		q[i]=q[i-1]^a[i];
		ma[q[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if (a[i]==k)
		{
			ans++;
			now=i;
			t[ma[q[i]]]=i;
			continue;
		}
		long long x=k^a[i]^q[i-1];
		if (t[ma[x]]!=0&&t[ma[x]]>=now)
		{
			ans++;
			now=i;
		}
		else if (now==0&&x==0)
		{
			ans++;
			now=i; 
		}
		t[ma[q[i]]]=i;
	}
	cout <<ans;
	return 0;
}

