#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
int n,k;
int a[N],p[N],f[N],t[N];
int work1(){
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			p[i]=i;
			continue;
		}
		int sum=a[i];
		for(int j=i+1;j<=n;j++){
			sum^=a[j];
			if(sum==k){
				p[i]=j;
				break;
			}
		}
	}
	for(int i=n;i>=1;i--){
		f[i]=t[i+1];
		if(p[i]!=-1)f[i]=max(f[i],f[p[i]+1]+1);
		t[i]=max(f[i],t[i+1]);
	}
	return f[1];
}
signed main(){
	//9:07-9:55 expect:60pts
	/*感觉这个DP没什么优化前途
	求最大值部分可以每次更新完之后动态记录一下当前f[i]-f[n]的最大值
	这样可以实现O(n)的DP
	但是预处理的O(n^2)怎么办呢
	算了不管了先打T4部分分 
	11:01:
	先把DP搞成O(n)的吧，这样预处理部分不是严格O(n^2)，可能冲过去一些点？ 
	11:06搞完了 
	0.1s过大样例，有机会！ 
	希望CCF数据水一点吧... 
	 */
	ios::sync_with_stdio(false);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(p,-1,sizeof p);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	/*if(n<=10000)*/cout<<work1();
	return 0;
}
