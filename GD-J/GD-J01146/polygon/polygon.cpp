#include<bits/stdc++.h>
#define MOD 998244353 
using namespace std;
int n,a[5009];
long long ans;
void dfs(int k,int s,int maxx){
	if(k>=3&&s>2*maxx){
		ans++;
	}
	for(int i=k;i<n;i++){
		dfs(k+1,s+a[i],a[i]);
	}
}
int main(){
	freopen("polygon.in","w",stdin);
	freopen("polygon.out","r",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	dfs(1,0,0);
	cout<<ans%MOD<<endl;
	return 0;
}
