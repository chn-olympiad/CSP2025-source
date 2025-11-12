#include<bits/stdc++.h>
using namespace std;
int n,a[5001],b[5001],ans=0,n1;
void dfs(int s,int k,int m){
	if(s>n1){
		ans+=pow(2,m-k);
		ans%=998244353;
	}else{
		for(int i=k+1;i<=m;i++){
			dfs(s+b[i],i,m);
		}
	} 
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	for(int i=n;i>=3;i--){
		int cnt=0;
		for(int j=n-i+2;j<=n;j++){
			b[++cnt]=a[j];
		}
		n1=a[n-i+1];
		dfs(0,0,cnt);
	}
	cout<<ans;
	return 0;
} 
