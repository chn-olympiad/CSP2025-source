#include<bits/stdc++.h>
#define pii pair<int, int>
#define st first
#define nd second
using namespace std;
int read(){
    int x=0, f=1;
    char ch=getchar();
    for(ch;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
    for(ch;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*f;
}
constexpr int INF=1e9, N=5e5+5, A=(1<<21)+5;
int n, k, a[N], sum[N], buc[A], L, R, ans;
/*
要求选出尽量多的两两不交区间, 使得每个区间的异或和均为 k
考虑前缀异或和, [l, r] 的异或和是 sum[r]^sum[l-1]
要想 [l, r] 的异或和 = k, 需要 sum[r] ^ sum[l-1] == k 
在此基础上希望选出的区间尽量多
找出每个左端点对应最小的右端点, 问题转化为经典贪心问题 
所有区间按照右端点为第一关键字, 左端点为第二关键字升序排序
不断选择, 覆盖
无需数据结构, 判断 i 和 i-1 是否相交即可 
时间复杂度 O(n log n) 瓶颈在排序 
*/
vector<pii> vec; 
inline bool cmp(pii x, pii y){
	if(x.nd==y.nd) return x.st<y.st;
	return x.nd<y.nd;
}
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
	n=read(), k=read();
	for(int i=1;i<=n;i++) a[i]=read(), sum[i]=sum[i-1]^a[i];
	memset(buc, -1, sizeof(buc)); // 初始化桶, buc[i] 存储 sum[x]=i 最小的 x 
	for(int i=n;i>=0;i--){
		if(buc[sum[i]^k]!=-1) // 前面有可以配对的右端点 
			vec.push_back(make_pair(i+1, buc[sum[i]^k]));
		buc[sum[i]]=i;
	}
	sort(vec.begin(), vec.end(), cmp);
	for(auto [l, r]:vec){
		if(L && R)
			if(l<=R)
				continue; // 相交 
		ans++;
		L=l, R=r;
	}
	cout<<ans;
	return 0;
}

