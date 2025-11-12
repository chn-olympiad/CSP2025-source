#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10,M=25000010,mod=998244353;
int n,k[N],sum,f[M],maxn;
void dp(int now)
{
	for(int t=maxn;t>=0;t--)
		f[t+k[now-2]]+=f[t],f[t+k[now-2]]%=mod;
	maxn+=k[now-2];
}
bool pd()
{
	for(int i=1;i<=n;i++)
		if(k[i-1]!=1) return false;
	return true;
}
int slow_pow(int a)
{
	int re=1;
	while(a!=0) a--,re=(re*2)%mod;
	return re;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>k[i-1];
	sort(k,k+n);
	if(pd())
	{
		cout<<(slow_pow(n)+mod-1-n*(n-1)/2-n)%mod<<endl;
		return 0;
	}
	f[0]=1;
	for(int i=2;i<=n;i++)
	{
		dp(i);
		for(int t=k[i-1]+1;t<=maxn;t++) sum=sum+f[t];
		sum=sum%mod;
	}
	cout<<sum<<endl;
	return 0;
}//T4 大约 60-80pts 
/////////////////////////////////////////感觉我现在无比的强大！！！
/////////////////////////////////////////T4 太水了，轻松骗到80pts 
/////////////////////////////////////////总分360是有的 
