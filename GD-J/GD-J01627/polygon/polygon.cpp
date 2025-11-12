#include<bits/stdc++.h>
using namespace std;
int n;
int ans=0;
int a[5005];
bool cpd(int a,int b){
	return a<=b;
}
void dfs(int i,int sum,int maxx,int k){
	if(sum>maxx*2 && k==0) {
		ans++;
		ans%=998244353;
		k=1;
	}
	if(i>n) return;
	dfs(i+1,sum+a[i],max(maxx,a[i]),0);
	dfs(i+1,sum,maxx,k);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cpd);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}

