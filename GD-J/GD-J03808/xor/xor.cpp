#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k;
int a[N];
int b[N];
int ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int l=1,r=1;l<=n;)
	{
		if((b[r]^b[l-1])==k)
		{
			ans++;
			l=r+1,r=l;
		}
		else
		{
			r++;
			if(r>n)l++,r=l;
		}
	}
	cout<<ans;
	return 0;
}
