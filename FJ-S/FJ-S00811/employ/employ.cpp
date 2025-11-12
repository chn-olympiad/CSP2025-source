#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int N=500;
const int mod=998244353;
int a[N+5],b[N+5];
int n,m;
int g[N+5];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0')b[i]=0;
		else b[i]=1;
	}
	if(m==n){
		int ans=1;
		for(int i=1;i<=n;i++)ans=ans*b[i]*(a[i]!=0);
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)g[i]=i;
	int ans=0;
	int cnt=0;
	for(int i=1;i<=n;i++)if(a[i]<=cnt||b[i]==0)cnt++;
	if(n-cnt>=m)ans++;
	while(next_permutation(g+1,g+n+1)){
		int cnt=0;
		for(int i=1;i<=n;i++)if(a[g[i]]<=cnt||b[i]==0)cnt++;
		if(n-cnt>=m)ans++;
		ans%=mod;
	}
	cout<<ans<<endl;
}
/*
最后一个OI赛季伴随一个滑稽的骗分拉开了序幕。
第一题5min。接着是T2，T3疯狂的卡常。
这两个多小时看着运行时间一点点下降，我很享受。但最终还是距离这荒谬的1s时限差了一点点。如果CCF神机天降，也许能拿到64+100。
差强人意的，切完两个蓝就开始骗分的省选过后，我离OI越来越远。一个暑假的拼搏，使我认为MO省队近在眼前。
可努力越多，失望越大。我从未如此认真地投入，也从未如此难过。奇葩的改卷把我的思维和心血判了死刑，甚至连写得与标答基本相同的题都被扣去大半分数。
当我浑身轻松地坐在CSP赛场，我居然突兀地感受到了编程的乐趣。
发现，探索，对更好、更优不懈的追求。 
*/
