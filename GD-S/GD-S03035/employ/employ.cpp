#include<bits/stdc++.h>
#define int long long

using namespace std;
const int mod = 998244353;
const int N = 1e6 + 10;

int n, m, a[N], ans = 1, cnt;
string s;

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == 0) cnt++;
	}
	if(n == m + cnt){
		for(int i = 1; i <= n; i++){
			ans *= 2;
			ans %= mod;
		}
		cout << ans << endl;
	}else cout << 0 << endl;
}

/*
哈哈哈又是我，写完游记也有点无聊剩45分钟打算留20分钟检查15分钟吐槽10分钟上厕所
槽点1：开始的时候密码发错了，少了一个数字，拖延3分钟左右虽然没多久
2：我检查一份代码1个小时（先说结果：数组开5 * 1e7，多打了一个0气死我了，电脑的报错也是奇怪execute这个词看不懂翻译不出来
重启一遍之后还是运行不了，我又重新下了一个Dev也不行，再重启一遍也不行，最后没招了当时真的有点崩溃
询问监考老师也没有回答，他原话是我自己的代码写的他也不知道为什么
最后还是运气好发现了这个错误
3：神奇，电脑有毒，每次直接点保存在桌面的.cpp文件都点不开
我也以为是bug，又重启一次（当然，每次重启都要保存一遍之前的东西滴）
重启完不到5分钟监考老师就说这个电脑点不开正常的，让后叫我们别关掉
那我想问了，为啥我右键打开不行，但是Dev里面点文件打开却可以
4：上午就听别人说J前两题简单后面难，下午s应验了
5：没什么槽点了随便写写
6：水时长，看上去写的多主要是
7：ok时间到检查去了 
 
*/ 
