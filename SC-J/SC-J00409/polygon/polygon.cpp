#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
const int mod=998244353;
int n,a[maxn];
long long ans;
void dfs(int x,int pol,int sum,int maxk){
	if(pol==0){
		if(sum>maxk*2){
			ans++;	
			ans%=mod;
		} 
		return;
	}
	for(int i=1;i<=n-x;i++){
		dfs(x+i,pol-1,sum+a[x+i],max(a[x+i],a[x]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			dfs(j,i-1,a[j],a[j]);
		}
	}
	cout<<(ans%=mod);
	return 0;
} 