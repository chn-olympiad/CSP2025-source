#include<bits/stdc++.h>
using namespace std;
int a[5010],n;
long long ans,mod=998244353;
void dfs(int x,int s,int h){
	if(h+n-x<3) return;
	if(h>=2)
		for(int i=x+1;i<=n;i++)
			if(s>a[i]){
				ans++;
				ans=ans%mod;
			}
	for(int i=x+1;i<=n;i++)
		dfs(i,s+a[i],h+1);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dfs(i,a[i],1);
	}
	cout<<ans;
	return 0;
}
