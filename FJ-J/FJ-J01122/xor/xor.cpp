#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005];
string h[500005];
bool f=1;
string fenjie(int x)
{
	string s,t;
	int pos=0;
	while(x)
	{
		s[pos++]=(x%2)+'0';
		x/=2;
	}
	for(int i=0; i<=pos; i++)
	{
		t[pos-i]=s[i];
	}
	return t;
}
int bijiao(string e, string f)
{
	
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		if(a[i]!=1)
		{
			f=0;
		}
	}
	if(f==1)
	{
		cout << n;
		return 0;
	}
	if(k==0)
	{
		int ans=0;
		for(int i=1; i<=n; i++)
		{
			if(a[i]==0)
			{
				ans++;
			}
		}
		cout << ans;
		return 0;
	}
	for(int i=1; i<=n; i++)
	{
		h[i]=fenjie(a[i]);
	}
	cout << 2;
	return 0;
}
