#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m;
char s[514];
int pat[514],num[514];
int ans=0;
void print()
{
	return;
}
bool check()
{
	int fail=0,pass=0;
	for(int i=1;i<=n;i++)
	{
		if(fail>=pat[num[i]]) {fail++;continue;}
		if(s[i-1]=='0') {fail++;continue;}
		if(s[i-1]=='1') pass++;
		if(pass>=m) return 1;
	}
	return 0;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool flg=1;
	cin>>n>>m;
	for(int i=0;i<n;i++) {cin>>s[i];if(s[i]=='0') flg=0;}
	for(int i=1;i<=n;i++) cin>>pat[i],num[i]=i;
	if(m==n&&!flg) {cout<<0;return 0;} 
	if(flg)
	{
		int f=1;
		for(int i=2;i<=n;i++) f=f*i%mod;
		cout<<f%mod;
		return 0;
	}
	sort(pat+1,pat+n+1);
	do
	{
		print();
		if(check()) ans=(ans+1)%mod;
	}while(next_permutation(num+1,num+n+1));
	cout<<ans%mod;
	return 0;
}
//I love CCF
//rp++;
/*
	亲爱的 别生气 游戏而已
	不过是哈夫币
	亲爱的 别撤离 我们一起
	葬在桥这里
	亲爱的 别逃离 隔壁监狱
	我也在那等你
	巡飞弹 目的地 永远是你
	贴着地飞行
	密码的 还七夕 我在家里
	玩航天绝密
*/ 

