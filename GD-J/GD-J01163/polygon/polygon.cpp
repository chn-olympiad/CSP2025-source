#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans;
int a[5100],b[5100];
inline void dfs(int nn,int x,int k,int sum){
	if(x==nn){
		if(sum>2*a[k])ans++,ans%=mod;
	}else{
		for(int i=k+1;i<=n;i++){
			b[x+1]=a[i];
			dfs(nn,x+1,i,sum+a[i]);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(i,0,0,0);
	}
	cout<<ans;
	return 0;
}

