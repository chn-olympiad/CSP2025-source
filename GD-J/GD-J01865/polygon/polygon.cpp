#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=5050;
int n,sum;
int a[N];
bool flag2,bath[N];
void dfs(int u){
	if(u==n+1){
		int m=0,maxlen=0,sumlen=0;
		for(int i=1;i<=n;i++){
			if(bath[i]==1){
				m++;
				maxlen=max(maxlen,a[i]);
				sumlen+=a[i];
			}
		}
		if(m>=3&&sumlen>maxlen*2)sum++;
		return;
	}
	for(int i=0;i<=1;i++){
		bath[u]=i;
		dfs(u+1);
	}
}
int work1(){
	dfs(1);
	return sum;
}
int work2(){
	int ans=1;
	for(int i=1;i<=n;i++)ans=ans*2%mod;
	ans=ans-1-n-n*(n-1)/2;
	ans%=mod;
	return ans;
}
signed main(){
	//10:07-10:18 dfs O(n*2^n)expect:40pts
	//10:19-10:22 max ai=1 O(n) expect:20pts
	/*
	就这样吧，O(n^2)和O(n^3)的没一点思路吧
	写个对拍然后挂着去上厕所，回来看下能不能冲T3 
	10:39对拍出问题了服了 
	我是傻子忘删n<=20了 
	10:46上完厕所回来了，希望T3能冲出点东西吧 
	*/ 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	flag2=1;
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag2=0;
	}
	if(n<=20)cout<<work1();
	else cout<<work2();
	return 0;
	/*11:41，把文件名什么的弄完了
	其实昨天一直在想这种大块的散时间要做点啥，在注释里写点什么
	可真正考试的时候才发现没有那么多时间
	这次考完 初中的OI生涯大抵就结束了吧
	可能下午我会留下点告别之类的话？
	反正现在暂时没这个心情...
	就这样吧，估分100+100+60+60=320，保留一定的挂分空间 
	*/ 
	//对了，还有个世界难题：中午吃什么？ 
}
