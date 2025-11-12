//RP++
#include<bits/stdc++.h>
using namespace std;
const int M=998244353,N=5e3+100;
int a[N],n,ans;
inline void dfs(int now,const int P,int sum,vector<int>vec,const int pos){
	vec.push_back(a[now]);
	sum+=a[now];if(sum>P){++ans;
//		cout<<(++ans)<<":";for(int x:vec)cout<<x<<" ";
//		cout<<P<<"\n";	
	}
	for(int i=now+1;i<pos;++i)dfs(i,P,sum,vec,pos);
	return (void)(ans%=M);
}
inline void solve(int p){
	int diff=a[p];vector<int>v;v.clear();
	for(int i=1;i<p;++i)dfs(i,diff,0,v,p);
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=3;--i)solve(i);
	cout<<ans;
	return 0;
}
/*
十年-陈奕迅
如果那两个字没有颤抖
我不会发现我的手
怎么说出口
也不过是分手
如果对于明天没有要求
牵牵手就像旅游
成千上万个门口
总有一个人要先走
怀抱既然不能逗留
何不在离开的时候
一边享受
一边泪流
十年之前
我不认识你
你不属于我 
我们还是一样
陪在一个陌生人左右
走过渐渐熟悉的街口 
十年之后
我们是朋友
还可以问候
只是那种温柔
再也找不到拥抱的理由
情人最后难免沦为朋友
怀抱既然不能逗留
何不在离开的时候
一边享受
一边泪流
十年之前
我不认识你
你不属于我 
我们还是一样
陪在一个陌生人左右
走过渐渐熟悉的街口 
十年之后
我们是朋友
还可以问候
只是那种温柔
再也找不到拥抱的理由
情人最后难免沦为朋友
直到和你做了多年朋友
才明白我的眼泪
不是为而流
也为别人而流


*/ 
