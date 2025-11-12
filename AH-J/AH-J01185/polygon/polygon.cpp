#include<bits/stdc++.h>
using namespace std;
int n;
int a[5050];
long long ans=0;
int v[5050];
void dfs(int i,int sum,int maxl){
	if(v[i]!=1){
		v[i]=1;
		sum+=a[i];
		maxl=max(a[i],maxl);
		if(sum>(maxl*2)){
			ans=(ans+1)%998244353;
			return;
		}
	}
	dfs(i+1,sum+a[i],maxl);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
