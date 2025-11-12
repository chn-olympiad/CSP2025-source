#include<bits/stdc++.h>
#define int int64_t
#define mod 998244353
using namespace std;
int a[505];
int C(int n,int m){//C_n^m
	int ans=1;
	for(int i=n;i>=n-m+1;i--){
		ans=ans*i%mod;
	}
	int chu=1;
	for(int j=1;j<=m;j++){
		chu=chu*j%mod;
	}
	return ans/chu;
}
int32_t main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int n,k;
	string s;
	cin>>n>>k>>s;
	int O=0;
	for(int i=0;i<n;i++){cin>>a[i];if(a[i]==0)O++;}
	if(n-O<k){
		cout<<0;
		return 0;
	}else if(!O){
		cout<<1;
		return 0;
	}
	cout<<C(n-k,O);
	return 0;
}
//特殊性质 A
