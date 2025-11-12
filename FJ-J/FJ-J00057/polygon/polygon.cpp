#include<bits/stdc++.h>
using namespace std;
int n,a[50001],ans;
long long sum;
int dfs(int i,int w,int v,int m){
	if(i==n+1){
		if(v>m*2&&w>2)return 1;
		else return 0;
	}
	return dfs(i+1,w+1,v+a[i],max(m,a[i]))+dfs(i+1,w,v,m);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=30)cout<<dfs(1,0,0,0);
	else{
		for(int i=3;i<=n;i++){
			sum+=((n-1)*n/2)%998224353;
			sum%=998224353;
		}
		cout<<sum;
	}
	return 0;
}
