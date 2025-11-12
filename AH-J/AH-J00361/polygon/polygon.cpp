#include<bits/stdc++.h>
using namespace std;
long long mo=998244353;
int n;
long long ans;
int a[10000];
void dfs(int i,int he,int maxn){
	if(i==n){
		return;
	}
	if(he>2*maxn){
		ans=(ans+1)%mo;
	}
	dfs(i+1,he,maxn);
	maxn=max(maxn,a[i+1]);
	dfs(i+1,he+a[i+1],maxn);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,-1);
	cout<<ans-1;
	return 0;
}
