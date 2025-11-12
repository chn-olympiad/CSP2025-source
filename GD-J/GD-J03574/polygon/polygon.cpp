#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[5010],cnt;
void dfs(ll w,ll sum,ll maxn){
	if(w==n){
		if(sum>maxn*2){
			cnt++;
		}
		return;
	}
	dfs(w+1,sum+a[w],max(maxn,a[w]));
	dfs(w+1,sum,maxn);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<cnt%998244353;
	return 0;
} 
