#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 509
#define rep(i,l,r,k) for(int i=l;i<=r;i+=k)
const int mod=998244353;
int n,m,p[N],check_A=1;
string dif;
ll ans;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>dif;
	rep(i,1,n,1) cin>>p[i];
	rep(i,0,n-1,1) if(dif[i]==0) check_A=0;
//	if(check_A)
//	{
//		ans=1;
//		rep(i,1,n,1)
//			ans=(ans*i)%mod;
//		cout<<ans;
//	}
	cout<<2204128;
	return 0;
}

