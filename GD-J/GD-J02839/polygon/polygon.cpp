#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],f[5005][10005],an;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	f[0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=2*a[n]+1;j++)
		{
			f[i+1][j]=(f[i+1][j]+f[i][j])%mod;
			f[i+1][min(j+a[i+1],2*a[n]+1)]=(f[i+1][min(j+a[i+1],2*a[n]+1)]+f[i][j])%mod;
			if(min(j+a[i+1],2*a[n]+1)>2*a[i+1])an=(an+f[i][j])%mod;
//			cout<<i<<' '<<j<<' '<<f[i&1][j]<<' '<<an<<'\n';
		}
	}
	cout<<an;
	return 0;
}
/*
当弱小的我打完前4题时，比赛已经过去了1个小时，1个小时打完4道题，大样例全过，尽管大样例不是很大。
弱小的我喜欢这种AK的感觉
玩植物大战僵尸和PVZ还有各种游戏
这场比赛非常奇怪，连弱小的我都能一眼秒，感觉会有很多人AK
在我看来，这一把已经稳了，今年感觉简单了好多，T4最多绿的感觉，也可能是我变强了。
不知道其他大蛇打的怎么样。
sto Skyler_Yunxi orz
sto Zyj6 orz
sto YY0707 orz
sto less_than orz
祝S组一帆风顺，和J组一样能够AK。
祝所有人RP++
*/ 
