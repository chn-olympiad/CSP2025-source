#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,m,cnt;
int a[501];
int b[501];
string str;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>str;
	bool p=1;
	for(int i=1;i<=n;i++)
	p&=(str[i-1]-'0');
	int t=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=i;
		t+=(a[i]==0);
	}
	if(p)
	{
		long long a=1;
		for(int i=100-t;i>=1;i--)
		a=(a*i)%mod;
		cout<<a;
		return 0;
	}
  	do{
		int t=0;
		for(int i=1;i<=n;i++)
		{
			if(str[i-1]=='0')
			{
				t++;
				continue;
			}
			if(t>=a[b[i]])
			{
				t++;
				continue;
			}
		}
		if(n-t>=m)
		cnt=(cnt+1)%mod;
	}while(next_permutation(b+1,b+n+1));
	cout<<cnt;
}
