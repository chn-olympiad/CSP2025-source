#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=550;
const int mod=998244353;
int n,m,ans,sumc;
int s[N],c[N],bath[N];
bool vis[N];
bool flag3;
string t;
void dfs(int u){
	if(u==n+1){
		int sumc=0,sumans=0;
		for(int i=1;i<=n;i++){
			if(sumans>=m)break;
			if(c[bath[i]]<=sumc){
				sumc++;
				continue;
			}
			if(s[i]==0)sumc++;
			else sumans++;
		}
		if(sumans>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			bath[u]=i;
			vis[i]=1;
			dfs(u+1);
			vis[i]=0;
		}
	}
}
int work1(){
	dfs(1);
	return ans%mod;
}
int work2(){
	for(int i=1;i<=n;i++)if(s[i]==0)return 0;
	if(sumc>0)return 0;
	int ans=1;
	for(int i=1;i<=n;i++)ans=ans*i%mod;
	return ans;
}
signed main(){
	flag3=1;
	ios::sync_with_stdio(false);
	//17:29-17:51 DFS O(N!) 8pts
	//17:51-17:55 m=n O(N) 4pts
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	cin>>t;
	for(int i=0;i<t.size();i++)s[i+1]=t[i]-'0';
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++){
		if(s[i]!=1)flag3=0;
		if(c[i]==0)sumc++;
	}
	if(n<=18)cout<<work1();
	else if(m==n)cout<<work2();
	else cout<<0;
	/*
	爆炸了...
	T2忘记最小生成树怎么写
	T3写了1.5h的假做法...
	只能说一年前学这些算法时候的随意，不认真
	终究化成考场上的无力
	一年前射出的子弹在CSP-S2025考场上正中眉心...
	就考成这鬼样子也没有NOIP了
	把之前的看到的一段话写出来吧，谨以此缅怀,不然在脑子里烂掉怪可惜的...
	每一个OIer的生涯都从一次CSP-J/S开始
	也大多从一次CSP-J/S结束
	如果这是你的第一次CSP-J/S
	祝你的OI生涯如夏花般绚烂
	如果这是你的最后一次CSP-J/S
	祝你的OI回忆如繁星般璀璨...
	我高中还会接着学下去吗？ 
	还有3 分钟结束，就这样了 
	*/ 
	return 0;
}
