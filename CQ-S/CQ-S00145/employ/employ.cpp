#include<bits/stdc++.h>
using namespace std;
int n,m,ans,c[505],Test[505];
char s[505];
const int mod=998244353;
bool mark[505];
bool pd(int a[]){
	int sum=0,fang=0;
	for(int i=1;i<=n;i++){
		if(fang>=a[i]){
			fang++;
			continue;
		}
		if(s[i]=='0')fang++;
		else sum++;
	}
	if(sum>=m)return 1;
	return 0;
}
void dfs(int now){
	if(now==n){
		if(pd(Test))ans++;
		ans=ans%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(mark[i])continue;
		mark[i]=true;
		Test[now+1]=c[i];
		dfs(now+1);
		mark[i]=false;
		Test[now+1]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool A=true;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(0);
	cout<<ans;
	return 0;
}
/*
100+0+15+8=123
仅剩的9Min应该也调不出来T2 
应该是要退役了（最多还能活到明年选基科班） 
再见OI
我想我这两年没有亏待你
但是现实却是J320 S123 
J去年因为T2没有memset初始化而挂掉100分
今年应该也没什么波动
最多就是从4级勾变成了5级勾吧
两年前，我满怀希望的看向你
我以为我可以……
现在，对你道别仍有许多的不舍
或许我们注定不能相见， 
但我依然会爱着你 
我会记得我因为热爱而做过的每一道题
希望历史不要忘记
还有这么一个人 
曾经深爱过OI
……
------1368090（洛谷uid，但应该也快注销了） 
*/ 
