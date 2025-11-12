#include<bits/stdc++.h>
using namespace std;
int n,ts=3,a[5003],sum,ans=0,cans=0;
void dfs(int sum,int m,int l,int t,int k){
	if(k==t){
		if(sum>=m*2)
			ans++;
	}
	for(int i=l+1;i<=n;i++){
		m=max(m,a[i]);
		dfs(sum+a[i],m,i,t,k);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(ts=3;ts<=n;ts++){
		dfs(0,0,0,ts,1);
	}
	cout<<ans;
	return 0;
} 
