#include<bits/stdc++.h>
#define int long long
#define fore(x,m,n) for(int x=m;x<=n;x++)
using namespace std;

const int mod=99824453;
int n,m,x;
string s;

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	fore(i,1,n) cin>>x;
	int ans=1;
	fore(i,m+1,n) ans=(ans*i)%mod;
	cout<<ans;
	return 0;
}
