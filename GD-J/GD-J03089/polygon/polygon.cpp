#include<bits/stdc++.h>
using namespace std;
int a[5005];	
int n;
long long ans=0;
void dfs(int x,int pr){
	for(int i=x+1;i<=n;i++){
		if(a[i]<pr)ans++;
		ans%=998244353;
		dfs(i,pr+a[i]);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[3]<a[1]+a[2])cout<<1;
		else cout<<0;
	}
	else if(a[n]==1){
		for(int i=3;i<=n;i++){
			ans+=n-i+1;
			ans%=998244353;
		} 
		cout<<ans;
	}
	else{
		dfs(0,0);
		cout<<ans;
	}
}
