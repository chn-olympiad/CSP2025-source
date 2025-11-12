#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+5;
int n,a[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3)
	{
		int maxn=0;
		for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
		int sum=a[1]+a[2]+a[3];
		if(sum>maxn*2) cout<<1;
		else cout<<0;
	}
	return 0;
}
