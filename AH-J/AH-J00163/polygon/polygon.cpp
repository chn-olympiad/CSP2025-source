#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,a[5005],s[5005],ans;
void dfs(int id,int maxn,int dep,int s){
	if(dep>=3 && s>maxn*2)ans++;
	if(id>n)return;
	for(int i=id;i<=n;i++){
		if(dep<1 && i>=n-1)break;
		if(dep<2 && i>=n)break;
		int k=maxn;
		if(a[i]>maxn)k=a[i];
		dfs(i+1,k,dep+1,s+a[i]);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
