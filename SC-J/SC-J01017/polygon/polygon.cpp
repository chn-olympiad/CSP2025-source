#include <iostream>
#include <algorithm>
using namespace std;
const int N=5000+5,M=1e4+5,MOD=998244353;
int a[N],f[M],mx;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;cin >> n;
	for (int i=1;i<=n;++i) cin >> a[i];
	sort(a+1,a+1+n);mx=a[n];
	int ans=0;f[0]=1;
	int lim=2*mx;
	for (int i=1,j,w;i<=n;++i){
		w=a[i]<<1;
		for (j=lim+1;j>=lim-a[i]+1;--j) 
			ans+=f[j],f[lim+1]+=f[j],ans=(ans>=MOD?ans-MOD:ans),f[lim+1]=(f[lim+1]>=MOD?f[lim+1]-MOD:f[lim+1]);
		for (j=lim;j>=a[i];--j){
			if (j>w) ans+=f[j-a[i]],ans=(ans>=MOD?ans-MOD:ans);//合法
			f[j]+=f[j-a[i]];f[j]=(f[j]>=MOD?f[j]-MOD:f[j]);
		}
	}
	cout<<ans<<"\n";
	cout.flush();
	return 0;
}
/*
史册汉简处，却详载
#Shang4Shan3Ruo6Shui4
首先排序，从小到大，则max那一维可以去掉了
不对啊这不就做完了吗？枚举最大的是那个数统计就可以了
哦还要做一维dp，有点特殊
f(i,j) 表示前i个数，选出来的数的和是j，若j=10001则j>000，其方案数
做完了，AK了！

haojiandan
wojide zhiqian bushi youdao leisi de ti ma ?
yuanliang wode yingyu shuiping!!!
J组超纲啦！
J zu chaogangla!
\sigma is gaozhongshuxue de dongxi
danshi J zu jinjin yaoqiu zhangwo chuzhongshuxuezhishi
jihe yeshi gaozhong de (jinguan houmian you jieshi)

never give up!(now is 9:00a.m.)AK!
*/