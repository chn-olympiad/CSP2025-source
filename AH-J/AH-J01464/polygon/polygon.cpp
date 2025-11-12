#include<bits/stdc++.h>
using namespace std;
const long long int N=5e3+5,Mod=998244353;
long long int n,maxn,ans;
long long int a[N],b[N];
void dfs(long long int k,long long maxn,long long int sum){
	if(sum>2*maxn){
		ans++;
	}
	if(k>n){
		return;
	}
	maxn=max(maxn,a[k]);
	dfs(k+1,maxn,sum);
	
	dfs(k+1,maxn,sum+a[k]);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<"0";
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
