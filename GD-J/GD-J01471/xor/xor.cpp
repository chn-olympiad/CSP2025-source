#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,la,cnt,now;
int a[N],s[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]^a[i];
	}
	int now=0;
	for(int i=1;i<=n;i++)
	{
		if((s[i]^now)==k)
		{
			cnt++;
			now=s[i];
		}
	}
	cout<<cnt;
	return 0;
}
