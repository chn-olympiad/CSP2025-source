#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int f[5005];
long long ans;
void dfs(int x,int y,int sum,int m){
	if(x>=3){
		if(sum>m*2){
			ans++;
//			cout<<x<<endl;
//			cout<<endl;
//			for(int i=0;i<x;i++) cout<<f[i]<<" ";
//			cout<<endl;
			ans%=998244353;
		}
		if(x==n) return;
	}
	for(int i=y;i<n;i++){
		f[x]=a[i];
		dfs(x+1,i+1,sum+a[i],max(m,a[i]));
		f[x]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
