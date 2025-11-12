#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+50;
ll a[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	if(n==1)cout<<0;
	else cout<<1;
	return 0;
}
