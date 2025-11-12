#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int a[100010];
int b[100010];
int c[100010];
int bm[100010];//所属部门
int ay,by,cy;//数量
int px[100010];//排序差值 
void zxk(){
	int n;
	cin >> n;
	int ans = 0;
	ay = 0,by = 0,cy = 0;
	for (int i = 1 ; i <= n ; i++){
		cin >> a[i] >> b[i] >> c[i];
		if(a[i] >= b[i] && a[i] >= c[i]){
			ans += a[i];
			ay++;
			bm[i] = 1;
		}else if(b[i] >= a[i] && b[i] >= c[i]){
			ans += b[i];
			by++;
			bm[i] = 2;
		}else{
			ans += c[i];
			cy++;
			bm[i] = 3;
		}
	}
	
	int sc;//要转移的人数 
	if(ay > n/2){
		sc = ay-(n/2);
		int sum = 0;
		for (int i = 1 ; i <= n ; i ++){
			if(bm[i] == 1){
				px[++sum] = a[i] - max(b[i],c[i]);
			}
		}
		sort(px+1,px+1+ay);
	}else if(by > n/2){
		sc = by-(n/2);
		int sum = 0;
		for (int i = 1 ; i <= n ; i ++){
			if(bm[i] == 2){
				px[++sum] = b[i] - max(a[i],c[i]);
			}
		}
		sort(px+1,px+1+by);
	}else if(cy > n/2){
		sc = cy-(n/2);
		int sum = 0;
		for (int i = 1 ; i <= n ; i ++){
			if(bm[i] == 3){
				px[++sum] = c[i] - max(a[i],b[i]);
			}
		}
		sort(px+1,px+1+cy);
	}else{
		cout << ans << endl;
		return;
	}
	for (int i = 1 ; i <= sc ; i ++){
		ans -= px[i];
	}
	cout << ans << endl;
}
signed main (){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin >> t;
	while(t--){
		zxk();
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

将全部放最大值，如果都不超过n/2就是答案

如果最大的超过n/2
分析一下，如果a放了超过n/2的，
那将其转移出去的最优解一定
无法让另外两个到达n/2以上，
也就是同时只可能有一个部门放满
考虑贪心

我们在超过n/2的部门
比如说A

那么记录A中元素的第二大部门的数，求差值
即转移会使答案变小多少，

那么贪心转移最小的，然后输出答案

考虑如何实现
似乎不用排序
我们先把每个元素求出所属的部门
在最大部门中记录每一个差值，
丢到一个数组里排序，
好吧要排序，
然后将答案减去前a.size-n/2的元素
好的开打 
*/ 

