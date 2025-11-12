#include<bits/stdc++.h>
using namespace std;
int a[500005];
//怎么感觉像线段树 炸了孩子们 
//st上吧(叹
//今年题好像没那么难不管了 
//推了一下有点难受搞2样例去了 
//回来了 闹心 不想搞这个！
//我去做一下T4了 不要太想我 
//总感觉34好像
//是ST就应该好好去搞RMQ啊喂 这到底是啥啊 我现在只能想到N3算法坐牢 还是太蒻了 
//336放过我 这咋写厚礼蟹
//先暴力吧只有八十分钟了 正解也冲不到
//写不了ST吧我真的。 
//其实自己也不知道写的是啥、有些东西没考虑到不过AB应该OK 
//11:16:42 估分100 + 100 + 30 + 48
//最低差不多 100 + 100 + 25 + 24? 别炸我心态好不好(主包想回家了
//炫了两口巧克力真的好吃 彳亍 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	int n , k;
	cin >> n >> k;
	int cnt = 0;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	if(n == 1){
		if(a[1] == k) cout << 1;
		else cout << 0;
		return 0;
	}
	if(n == 2){
		if(a[1] == a[2] && a[1] == k) cout << 2;
		else if((a[1] ^ a[2]) == k) cout << 1;
		else cout << 0;
		return 0;
	}
	for(int i = 1;i <= n;i ++){
		if(~a[i - 1]) a[i] ^= a[i - 1];
		if(a[i] == k) cnt ++ , a[i] = -1; 
	}
	cout << cnt;
	return 0;
}


