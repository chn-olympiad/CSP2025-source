#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		cout<<n/2;
	}
	return 0;
} 
