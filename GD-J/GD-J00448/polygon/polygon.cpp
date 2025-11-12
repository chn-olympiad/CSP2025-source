#include<bits/stdc++.h>
using namespace std;
const int N=5010;
const long long mod=998244353;
long long n,a[N];
long long upsum,ans,maxa;
long long bid[N];
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
//	freopen("polygno.in","r",stdin);
//	freopen("polygno.out","w",stdout);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	bid[0]=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i]+1;j<=maxa;j++) ans+=bid[j],ans%=mod;
		ans+=upsum,ans%=mod;
		upsum*=2,upsum%=mod;
		for(int j=maxa;j>=0;j--)
		{
			if(j+a[i]>maxa)
			{
				upsum+=bid[j],upsum%=mod;
			}
			else
			{
				bid[j+a[i]]+=bid[j],bid[j+a[i]]%=mod;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
luogu:shuaiqbr

Zan Yang CCF
1h zuo wan
gan jue neng AK
nan du red red yellow yellow
CCF liang xin
*/
