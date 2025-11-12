#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long a[10000];
long long n;
long long ans=0;
void dfs(long long x,long long h){
	if(x>=n)return;
	if(h>a[x])ans++;
	dfs(x+1,h+a[x]);
	dfs(x+1,h);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	dfs(0,0);
	cout<<ans%MOD;
	return 0;
}
