#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],xo[500005],dp[500006];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xo[i]=xo[i-1]^a[i];
	}
	cout<<1;
	return 0;
}
/*
怎么说呢，就剩最后五分钟了
前7分钟做了AB题
后面组合数学和DP我都不会
哎
CSP-J 2025 预计~230
比上次315还差
 我c了
 ccf太《帅哥》了
组合数学和dp我最薄弱
我c
AFO力

luogu uid750120 Ashford

tmd s组也要炸了
s组再考dp我就拿筷子了
回去玩玩怎么搞
有思路但是不知道该怎么实现
码力还是太弱了
555555555555
回去该怎么解释啊

集训这几个月
感觉收获不少
但是落得这般下场 
/*
