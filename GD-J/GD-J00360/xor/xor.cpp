#include<bits/stdc++.h>
using namespace std;
const int N=5e5+11;
int n,k,arr[N],sum[N];
long long ans;
set<int>st;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	sum[0]=0;//表示当前区间的异或和 
	st.insert(0);
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		sum[i]=sum[i-1]^arr[i];
		int tmp=sum[i]^k;
		if(st.find(tmp)!=st.end()){
			ans++,sum[i]=0;
			st.clear();
		}
		st.insert(sum[i]);
	}
	cout<<ans;
	return 0;
}
/*
xor优化版 O(nlogn) 

自测:
6 0
1 0 1 1 3 3 

愿此行,终抵群星 泉门永存 
icebird_ldyy code
*/

