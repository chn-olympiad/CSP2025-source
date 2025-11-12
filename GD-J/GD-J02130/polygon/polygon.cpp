#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],pp=998244353,ans;
void dfs(int s,int x,int y){
	if(s==n+1){
		if(x>2*y) ans++;
		ans%=pp;
		return;
	}
	dfs(s+1,x,y);
	dfs(s+1,x+a[s],a[s]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

