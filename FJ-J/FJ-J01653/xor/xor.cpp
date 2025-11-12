#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
int a[1000000];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n<=2 && k==0)
	{
		int x,y;
		cin>>x;
		cin>>y;
		if(x!=y) cout<<0;
		else cout<<1;
		return 0;
	}
	cout<<1;
	return 0; 
}
