#include <bits/stdc++.h>
using namespace std;
int a[510000];
int vis[510000];
int xoor(int x,int y){
	int suum=a[x];
	for(int i=x+1;i<=y;i++){
		suum=suum^a[i];
	}
	return suum;
}
int vv(int x,int y){
	for(int i=x;i<=y;i++){
		if(vis[i]==1) return 0;
	}
	return 1;
}
void v2(int x,int y){
	for(int i=x;i<=y;i++){
		vis[i]=1;
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int k,n;int ans=0;int l=n;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k) {
			ans++;
			vis[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((xoor(i,j)==k)&&vv(i,j)==1){
				ans++;
				v2(i,j);
			}
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
