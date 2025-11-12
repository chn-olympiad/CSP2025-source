#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,mod=998244353;
int n,a[N],ans;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;int mi,sum=0; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];sum+=a[i];
		if(a[i]>a[i-1])mi=i;
	}
	if(sum>a[mi]*2)
	cout<<1;
	else cout<<0;
	return 0;
}
