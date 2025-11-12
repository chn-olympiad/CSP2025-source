#include<bits/stdc++.h>
using namespace std;
int n,k,a[5005],ans;
long long now;
bool vis[5005];
void dfs(int k,int d,int sum,int maxx){
	if(sum>maxx*2&&d>=3){
		ans++;
	}
	for(int i=k+1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			int monkey=max(maxx,a[i]);
			dfs(i,d+1,sum+a[i],monkey);
			vis[i]=0;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
