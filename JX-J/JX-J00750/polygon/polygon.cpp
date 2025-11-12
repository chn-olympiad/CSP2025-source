#include<bits/stdc++.h>
using namespace std;
int n,a[5005],vis[5005],ans;
void bfs(int x,int num,int mx){
	if(x>=4&&num>mx*2){
		ans++;
	}
	if(x==n+1) return;
	for(int i=x;i<=n;i++){
		if(vis[i]==0&&a[i]>=mx){
			vis[i]=1;
			bfs(x+1,num+a[i],a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polyfon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	bfs(1,0,0);
	cout<<ans%998244353;;
	fclose(stdin);
	fclose(stdout);

	return 0;
}
