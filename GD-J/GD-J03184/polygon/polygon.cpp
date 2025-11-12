//I love CCf forever!
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 5e3 + 5;
const int MOD = 998244353;
int n;
int ans;
int a[N];
void dfs (int now , int mx , int sum , int id) {//选了几个，选的最大值、总值，现在选第几个 
	if (sum > 2 * mx && now >= 3) ans++;
	ans %= MOD;
	if (id > n) return;
	dfs(now + 1 , max(mx , a[id]) , sum + a[id] , id + 1);//选 
	dfs(now , mx , sum , id + 1);//不选 
}
signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	
	cin >> n;
	for (int i = 1 ; i <= n ; i++) cin >> a[i];
	
	dfs(0 , 0 , 0 , 1);
	
	cout << ans;
	return 0;
}





//I love CCf forever!
//I love CCf forever!
//I love CCf forever!
//I love CCf forever!
//I love CCf forever!
//I love CCf forever!
//I love CCf forever!
//I love CCf forever!
//I love CCf forever!
//I love CCf forever!
//I love CCf forever!

/*
结束前半小时的发dian：
	题目难度概述： 
		这次的T1、T2感觉挺简单的一共一小时不到就写完了，能不能拿满不确定 
		希望我T1、T2能拿200分[保佑我球球了]
		T3T4有思路但总是不对？
		T3样例1234过了，但56的输出差很多
		T4连样例都过不了（感觉代码没问题啊），干脆放弃了
		T3T4一共给我20分吧[保佑我球球了]
	
	考场评价：
		还算干净，但不知是不是有人脱鞋，一大股臭味，闻了3个小时，快吐了 
	 
	回忆：
		C++才学一年，去年才刚接触一个月，初赛奇迹般过了，又学了一两个月就来考J组了，那时的头文件还是<iostream>
		T1（扑克）都没过，当时写了几十行if else，结果得了几十分
		我都已经初三了，明年的这时候就是以高中生的身份来靠 CSP了（能进 S 吧） 
		希望239天后（6月28）我能超常发挥，进入四大吧
		加油！
	
	最后祈祷：
		I love CCf forever!
		Please give me more over(than?) 220 score!
		I really want to reach the top of CSP-J , can you , CCF , give me a chance？
		How kind of CCF in this exam!
		Please!
		（英语不好，见谅） 
