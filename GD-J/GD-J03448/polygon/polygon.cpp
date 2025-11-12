#include<bits/stdc++.h>
using namespace std;
long long ans,n=1,k[5001],c,ma;
int vis[5001];
long long pl(int a){
	if(c>ma*2){
		ans++;
	}
	for(int i=a;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			c+=k[i];
			ma=k[i];
			pl(i);
			ma=k[i];
			c-=k[i];
			vis[i]=0;
		}
	}
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","W",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		vis[i]=0;
	}
	sort(k+1,k+n+1);
	pl(1);
	cout<<ans%998%244;
	return 0;
}
/*
 5
1 2 3 4 5

5
2 2 3 8 10
*/
