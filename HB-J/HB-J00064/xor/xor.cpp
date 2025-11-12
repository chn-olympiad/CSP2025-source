#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],s[500005],cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int b=0;
	for(int i=1;i<=n;i++)
	{
		int t;
		t=s[i]^s[b];
		if(t == k)
		{
			cnt++;
			b=i;
		}
	}
	cout<<cnt;
	return 0;
}
