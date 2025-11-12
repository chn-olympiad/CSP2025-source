#include"bits/stdc++.h"
using namespace std;
int n,k,a[510000],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			a[i]=0;ans++;
		}
	}
	if(n==1) if(a[1]==k) cout<<1;else cout<<0;
	if(n==2)
	{
		if(a[1]==k&&a[2]==k) cout<<2;
		else if(a[1]^a[2]==k||a[1]==k||a[2]==k) cout<<1;
		else cout<<0;
	}//5·ÖÌØÅÐ
}
