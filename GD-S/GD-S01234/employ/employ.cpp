#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int jie(int x){
	x%=MOD;
	for(int i=1;i<=x;i++){
		x*=(i%MOD);	
		x%=MOD;
	}
	return x%MOD;
}
int A(int m,int n){
	return (jie(n)/jie(m))%MOD;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;cin>>n>>m;
	string s;cin>>s;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	int ans=0;
	for(int i=m;i<=n;i++){
		ans+=A(m,n)%MOD;
		ans%=MOD;
	}
	cout<<ans%MOD;
	return 0;
}
/*
我想着
一个人 一整天
都不失落

就让我
喝醉后 唱着歌 
自娱自乐 

*/

