#include<bits/stdc++.h>
using namespace std;
const int N=5e3+55;
const long long MOD=998244353;
int n,arr[N],c[N];
long long ans;
void dfs(int x,int s){
//	if(s>2*arr[n]){
//		ans+=n-x+1;
//		return ;
//	}
	if(x>3){
		if(s>2*arr[c[x-1]]){
			ans++;
			ans%=MOD;
		}
	}
	if(x>n) return ;
	for(int i=c[x-1]+1;i<=n;i++){
		c[x]=i,s+=arr[i];
		dfs(x+1,s);
		c[x]=0,s-=arr[i];
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	if(n==3){
		cout<<(arr[1]+arr[2]+arr[3]>2*arr[3]?1:0);
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
/*
polygon暴力版 

务必保证前三题正确再做此题!!! 

愿此行,终抵群星 泉门永存 
icebird_ldyy code
*/

