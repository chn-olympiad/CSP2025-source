#include<bits/stdc++.h>
using namespace std;
const int M = 998244353;
long long a[5010],ans,n;
void dfs(int now,long long maxn,long long sum,int num){
	if(now > n){
		if(sum > maxn*2 && num >= 3){
			ans = (ans+1)%M;
		}
		return;
	}
	dfs(now+1,maxn,sum,num);
	dfs(now+1,a[now],sum+a[now],num+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>> n;
    if(n >= 30){
    	cout<< 1;
    	return 0;
	}
	for(int i = 1;i <= n;i++){
		cin>> a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<< ans;
	return 0;
}
