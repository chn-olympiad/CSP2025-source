#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	vector<int> a(n+5);
	//f[i]表示在第 i 位时,最多可以得到 f[i]个权值为 k 的子序列 
	vector<int> f(n+5);
	/*
	转移方程: 
	if (...) 
		f[i] = max(f[i], f[j] + 1)
	*/ 

	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			int xorsum=a[i],t=0;
			for(int p=i-1;p>=j;p--){//计算在i~j之间有多少种(权值==k)的情况 
				xorsum=xorsum^a[p];	//计算异或和 
				if(xorsum==k){		//如果权值相符 
					t++;			//可能的情况增加 一共 t 种 
					xorsum=a[p-1];	//继续判断可能的情况 
					p--;
				}
			}
//			cout<<i<<'~'<<j<<"xor is:"<<xorsum<<'\n';
			f[i]=max(f[i],f[j]+t);	//将 f[i] 更新 
			ans=max(ans,f[i]);		//取最大值做答案 
		}
		
	}
	cout<<ans;
	return 0;
}
