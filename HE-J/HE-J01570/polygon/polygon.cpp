#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum,fa,vis[5005];
void dfs(int ms,int x){
	if(ms==0){
		if(sum>a[x]*2){
			fa++;
		}
		return;
	}
	for(int i=x;i<=n;i++){
		if(vis[i]==0){
			sum+=a[i];
			vis[i]=1;
			dfs(ms-1,i);
			sum-=a[i];
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
	for(int i=3;i<=n;i++){
		dfs(i,1);
	}
	cout<<fa;
	return 0;
}
