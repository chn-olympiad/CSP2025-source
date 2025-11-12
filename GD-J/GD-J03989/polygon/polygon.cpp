#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int n,a[N],ans,c[N][N],infac[N];
bool bj=1;
inline void dfs(int step,int maxx,int sum){
	if(step==n+1){
		if(maxx*2<sum)ans++;
		return ;
	}
	dfs(step+1,maxx,sum);
	dfs(step+1,max(maxx,a[step]),sum+a[step]);
}
inline int fpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)(ans*=a)%=998244353;
		(a*=a)%=998244353;
		b>>=1;
	}
	return ans;
}
signed main(){
	freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n;
	for(int i(1);i<=n;++i){
		cin>>a[i];
		if(a[i]!=1)bj=0;
	}
	for(int i(0);i<=n;++i){
		c[i][0]=c[i][i]=1;
		for(int j(1);j<i;++j){
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	}
	if(bj){
		int anss=0;
		for(int i(3);i<=n;++i){
			(anss+=c[n][i])%=998244353;
		}
		cout<<anss<<'\n';
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
/*
没办法了，没有时间了,出题人良心啊，让我AC三题的好人啊，让我J比上年高 104 分好人啊。
但我还是太菜了，无法 AK  J 组，100+100+100+64=364 在此纪念 114514 1919810
我的同学初一已AK J 组，但 我初二还不行我真菜啊，望S组简单点吧，让我打 noip 吧啊啊啊。

没有可以思考的心智，
没有可以屈从的意志，
没有为苦难哭泣的声音，
生于神与虚空之手，
你必封印在众人梦中散布瘟疫的障目之光，
你是容器，
你是空洞骑士。 

祝所有人 rp++,看到这份代码的人while(1)rp++

我常常追忆过去...  

orz yy0707  
orz zjy6
orz Skyler_Yunxi
orz greater_than
orz xiaoyuhao
orz humaoxing
orz yuanhaorana
orz zssyt
orz less_than
orz ULL
orz 1vegetable
orz wangyuxuan2024
orz emmoy
orz CHD
orz CHDfan
orz yjxfan
orz wtc
orz ...
*/
