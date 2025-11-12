#include<bits/stdc++.h>
using namespace std;
int a[5010];
int n;
int ans=0;
void dfs(int i,int cnt,int k,int mx){
	if(i>n){
		if(k>=3&&cnt>mx*2){
			ans=(ans+1)%998244353;
		}
		return;
	}
	dfs(i+1,cnt+a[i],k+1,max(mx,a[i]));
	dfs(i+1,cnt,k,mx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
