#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[5005];
const int m=998244353;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans+=a[i];
	}
	sort(a+1,a+n+1);
	if(ans>a[n]) cout<<1;
	else cout<<0;
	return 0;
}
