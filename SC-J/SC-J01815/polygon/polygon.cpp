#include<bits/stdc++.h>
using namespace std;
int c[5005];
int a[5005];
int n,ans;

void dfs(int i,int b,int s,int mx){
	if(i>n){
		if(b>2&&s>mx*2){
			ans++;
			ans%=998244353;
		}
		return;
	}
	dfs(i+1,b,s,mx);
	c[b+1]=i;
	dfs(i+1,b+1,s+a[i],max(mx,a[i]));
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}