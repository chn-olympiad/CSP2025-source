#include <bits/stdc++.h>
using namespace std;
int v[5005],n,sum=0;long long s=0;
void dfs(int m){
	for(int x=m+1;x<=n;x++){
		if(sum>v[x])s=(s+1)%998244353;
		sum+=v[x];
		dfs(x);
		sum-=v[x];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int x=1;x<=n;x++){
		cin>>v[x];
	}
	sort(v+1,v+n+1);
	dfs(0);
	cout<<s%998244353;
	return 0;
}
