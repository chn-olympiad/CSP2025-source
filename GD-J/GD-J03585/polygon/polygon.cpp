#include<bits/stdc++.h>
using namespace std;
const long long P=998244353;
int n,a[5005];
long long ans;
void dfs(int maxx,int sum,int now){
	if(sum>maxx*2){
		ans++;
		ans%=P;
	}
	for(int i=now+1;i<=n;i++){
		dfs(max(maxx,a[i]),sum+a[i],i);
	}
	return;
}
int main(){
	ifstream r("polygon.in");
	ofstream w("polygon.out");
	r>>n;
	for(int i=1;i<=n;i++){
		r>>a[i];
	}
	dfs(0,0,0);
	w<<ans;
	cout<<ans;
	return 0;
}
