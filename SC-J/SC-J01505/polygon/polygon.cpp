#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+5,mod=998244353,M=1e5;
//ccf特有的棍木题
/*
luogu:Kanycta
Bilibili:UN_kny
Warthunder Asia :Kanycta
WoT Asia:UN_kanycta
QQ:2098410134
wx:gensokyo524
少羽牛逼！
少羽牛逼！
少羽牛逼！
少羽牛逼！
少羽牛逼！
*/
int n,ans,a[M],sum[M];
void p12()
{
	int cnt=0;
	int jc[N];
	jc[1]=1;
	for(int i=2;i<=n;i++)
	{
		jc[i]=jc[i-1]*i%mod;
	}
	for(int i=3;i<=n;i++)
	{
	//	cout<<jc[n]<<" "<<jc[i]<<endl;
		cnt+=jc[n]/jc[i];
	}
	cout<<cnt;
}
void dfs(int sm,int mx,int nw,int jbx)
{
//	if(sm==10&&mx==4)
	//{
	//	cout<<jbx<<endl;
	//}
//	cout<<nw<<endl;
	if(nw>n)
	{
		if(/*jbx>=2&&*/sm>mx*2)
		{
			ans++;
			ans%=mod;
	//		cout<<sm<<" "<<mx<<endl;
		}
		return;
	}
	if(jbx<2)
	{
		dfs(sm+a[nw],max(mx,a[nw]),nw+1,jbx++);
	}
	else //if(sm+a[nw]>2*max(mx,a[nw]))
	{
		dfs(sm+a[nw],max(mx,a[nw]),nw+1,jbx);
	}
	dfs(sm,mx,nw+1,jbx);
}
main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	bool pian=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		if(a[i]>1)pian=1;
	}
	if(pian==0)
	{
		p12();
		exit(0);
	}
	dfs(0,0,1,0);
	cout<<ans;
	return 0;
}//神人ccf,居然不让吃士力架
//30pts 诶 我太fvv了