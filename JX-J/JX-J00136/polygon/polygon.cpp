/*
./compile polygon a
./polygon
*/
#include<bits/stdc++.h>
#define pii pair<int,int>
#define lowbit(x) ((x)&(-(x)))
#define allof(o) (o).begin(),(o).end()
using namespace std;
const int mod=998244353;
map<int,int> f[5005];
int Pow2[5005];
int s[5005];
int a[5005];
int ans=0;
int n;
vector<int> v;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(*max_element(a+1,a+n+1)==1)
	{
		ans=Pow2[n];
		ans-=1;        ans%=mod;
		ans-=n;        ans%=mod;
		ans-=n*(n-1)/2;ans%=mod;
		return 0;
	}
	// if(n<=20)
	{
		for(int s=(1<<n)-1;s>0;s--)
		{
			int sum=0,ma=0,cnt=0;
			for(int i=1;i<=n;i++)
				if((s>>(i-1))&1)
					cnt++,sum+=a[i],ma=max(ma,a[i]);
			if(cnt<3)continue;
			if(sum>2*ma)ans++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}