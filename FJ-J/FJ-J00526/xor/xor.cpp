#include<bits/stdc++.h>
using namespace std;

// freopen() freopen() freopen() freopen() freopen()
// stdin

int a[500010],n;long long k;
long long ans;

long long qiu(int l,int r){
	long long h;
	h = a[l];
	for(int i = l+1;i<=r;i++){
		h|=a[i];
	}
	return h;
}

void dfs(int l,int u){
	if(u > n or l > n) return;
	if(qiu(l,u) == k) ans++;
	
	
	for(int i = u+1;i<n;i++){
		for(int j = i+1;j<=n;j++){
			dfs(i,j);
		}
	}
	return;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i] == k) ans++;
	}
	dfs(1,2);
	cout<<ans;
	return 0;
}
//freopen("xor.in","r",stdin); freopen("xor.in","r",stdin); freopen("xor.in","r",stdin); freopen("xor.in","r",stdin);
/*
不知道有没有人看见它qwq，
这个文件会被抽样吗qwq

希望有人看见它。。。
这个代码貌似只过了样例2.。。。
24小时前我连freopen都不会写。。。。
八个蛋

哦，考试完了之后回收代码貌似还要记住字节数，我就写一点水字节数的吧

现在是10：28分qwq，还有两个小时左右，真的很难熬啊，只能写一点笔记了哈

第三题和第四题都是dfs暴力的，不知道为啥我对dfs如此情有独钟，每次暴力就想用dfs

而且我有一个神奇的能力，每次在答案是正解的情况下总能写出常数最大的解法，不知道为什么qwq

第一次打csp,感觉自己这个绿名蒟蒻更蒟蒻了啊qwq

为什么我喜欢在一段文字后面加一个“qwq”啊qwq

我是真服了

我大概是这个世界上最菜的绿名了qwq

哦对了，我有一个小说，洛谷文章yqq5nd，昨天晚上刚刚更新完。 

算了，就写到这里，再加几个字来凑个整数字节数吧 

O_O6 OuO6  OwO6 OoO6  O_O6 OuO6  OwO6   OoO6  O_O6 OuO6  OwO6   OoO6  O_O6 OuO6  OwO6   OoO6  O_O6 OuO6  OwO6   OoO6  O_O6 OuO6  OwO6   OoO6  O_O6 OuO6  OwO6   OoO6  O_O6 OuO6  OwO6   OoO6  O_O6 OuO6  OwO6   OoO6  O_O6 OuO6  OwO6   OoO6  O_O6 OuO6  OwO6   OoO6  O_O6 OuO6  OwO6   OoO6  O_O6 OuO6  OwO6   OoO6  O_O6 OuO6  OwO6   OoO6  O_O6 OuO6  OwO6   OoO6 O_O6 OuO6  OwO6   OoO6  O_O6 OuO6  OwO6   OoO6  O_O6 OuO6  OwO6   OoO6  O_O6 OuO6  OwO6   OoO6  O_O6 OuO6  OwO6   OoO6    
*/
