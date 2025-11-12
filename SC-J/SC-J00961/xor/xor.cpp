#include<bits/stdc++.h>
#define int long long
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define dow(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
const int N=5e5+5;
int n,k;
int sum,cnt,ans,la;
int a[N];
map<int,int> mp;
map<int,bool> vis;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n)
	{
		sum^=a[i];
		int b=k^sum;
//		cout<<b<<endl;
		if(b==0||vis[b]) cnt=mp[b]+1;
		else cnt=0;
		mp[sum]=max({mp[sum],cnt,la});
		la=mp[sum];
		vis[sum]=1;
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}