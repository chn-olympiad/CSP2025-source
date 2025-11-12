#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

int n;
ll ans=0;
ll a[5001];
bool tp=1;
const ll mod=998244353;
bitset<5001>b;

void dfs(int n,int sum,int big,int begin,int end) {
	if(!n) {
		if(sum>big) ans++;
		return ;
	}
	for(int i=begin+1; i<=end; ++i) {
		if(!b[i]) {
			b[i]=1;
			dfs(n-1,sum+a[i],big,i,end);
			b[i]=0;
		}
	}
	return;
}

int main(int argc,char**argv) {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1; i<=n; ++i) {
		cin>>a[i];
		if(a[i]!=1) tp=0;
	}
	sort(a+1,a+1+n);


	for(int i=n; i>=3; --i) { //求[1,i-1]中比a[i]大的排列方式有几种
		//(正确解:O(1)~O(n))
		//只会暴力QAQ(10*4 40分)
		for(int j=2; j<i; ++j)
			dfs(j,0,a[i],0,i-1);
		ans%=mod;
	}


	cout<<ans;

	return 0;
}
