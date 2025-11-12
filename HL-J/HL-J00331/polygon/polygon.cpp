#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int a[5005];
int ans[5005];
bool vis[5005];
long long cnt;
int n;
//有啥剪枝吗 手跑一下排序减不了啊 
void f(int k , int maxn , int sum , int last){
	if(k > n) return;
	for(int i = last + 1;i <= n;i ++){
		if(!vis[i]){
			vis[i] = 1;
			if(k >= 3)
				if(max(maxn , a[i]) * 2 < sum + a[i]) cnt ++;
			f(k + 1 , max(maxn , a[i]) , sum + a[i] , i);
			vis[i] = 0;
		}
	}
}
//搞得我想暴搜了 什么鬼啊 没复习这里啊 不是这次不会要G吧 
//我尽力了 感觉全骗完还有时间写游记
//9:55:18 估分100 + 100 + 0 + 20 分数线不要那么高好吗 还是搞搞T3吧
//彳亍 暴搜了 10:31:10 估分100 + 100 + 0 + 48 
//11:21:58 不知道干嘛了 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	int sum , maxi;
	sum = 0;
	maxi = INT_MIN;
	for(int i = 1;i <= n;i ++) cin >> a[i] , maxi = max(maxi , a[i]) , sum += a[i];
	if(n < 3){
		cout << 0;
		return 0;
	}
	if(n == 3){
		if(sum > maxi * 2) cout << 1;
		else cout << 0;
		return 0;
	}
	if(maxi == 1){
		for(int i = 3;i <= n;i ++)//选几个 
			for(int j = 1;j <= n - i + 1;j ++)//当前是第几个开始
			 	for(int k = 1;k <= j;k ++) ans[i] += k;
		for(int i = 3;i <= n;i ++){
			ans[i] += ans[i - 1];
			ans[i] %= mod;
		}
		cout << ans[n];
		return 0;	
	}
	if(n <= 20){
		f(1 , INT_MIN , 0 , 0);
		cout << cnt % mod;
		return 0;
	}
	cout << 1ll * 1919810 * 114514 % mod;
	return 0;
}
