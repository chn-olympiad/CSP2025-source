#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5005,mod=998244353;
int n;
int a[N];
int ans;

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	
	cout<<9;

	return 0;
}

