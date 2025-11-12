#include <bits/stdc++.h>
using namespace std;
int n;
int a[5009];

int maxx=0;
int ans=0;

void dfs(int dep,int i,int maxt){
	if(dep>maxt && i>2){
		ans++;
		ans%=998244353;
		return;
	}
	if(i>=n) return;
	dfs(dep+a[i],i+1,(max(maxt/2,a[i]))*2);
	dfs(dep,i+1,maxt);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1,0);
	cout<<ans;
	return 0;
}
