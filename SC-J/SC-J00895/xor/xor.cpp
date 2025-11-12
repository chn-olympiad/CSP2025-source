//希望数量最大值 那么说明每个区间都尽可能的小 
//f1 O(n*n) 用前缀和权值的方式将权值预处理 单次查询复杂度为O(1)
//f2 f[i] 表示选到第i个时区间数量最大值 O(n)
// 而此时选择用每次用map维护(O(logn))当前权值上一次出现的位置
// 再通过直接查询该位置所需的异或值是否合法来更改f[i]
// 此时算法最终的复杂度为 O(nlogn) 完美 撒花 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int f[N];
int a[N];
int n,k;
map<int,int> mp;//表示此权值上一次出现的位置
int xor_sum[N]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	xor_sum[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xor_sum[i]=xor_sum[i-1]^a[i];
	} 
	for(int i=0;i<=N;i++) mp[i]=-1; 
	int last_end=0;
	mp[0]=0;
	for(int i=1;i<=n;i++){
		int need=k^xor_sum[i];
		f[i]=f[i-1];
		
//		cout<<i<<" "<<need<<endl;
		if(mp[need]>=last_end&&mp[need]<i){//如果map[i]==0 则说明未出现过 
//			cout<<mp[need]<<"*"<<i<<endl;
			f[i]++;
			last_end=i;
		}
		mp[xor_sum[i]]=i;//更新该权值最新出现位置
	}
	cout<<f[n]; 
	return 0;
}
