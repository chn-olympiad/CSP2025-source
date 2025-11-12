#include<bits/stdc++.h>
using namespace std;
long long a[500005],n;
bool check(long long sum,long long maxn){
	return sum>maxn*2;
}
long long dfs(int i,long long maxn,long long sum,int t){
	if(i==n){
		if((check(sum+a[i],(long long)max(maxn,a[i]))&&t+1>=3)||(check(sum,maxn)&&t>=3)){
			if((check(sum+a[i],(long long)max(maxn,a[i]))&&t+1>=3)&&(check(sum,maxn)&&t>=3)) return 2;
			return 1;
		}
		return 0;
	}
	return (dfs(i+1,(long long)max(maxn,a[i]),sum+a[i],t+1)+dfs(i+1,maxn,sum,t))%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	cout<<dfs(1,0,0,0)%998244353;
	return 0;
}
