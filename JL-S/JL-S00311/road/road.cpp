#include<bits/stdc++.h>
using namespace std()
int m,n,k,a[10005][10005],ans;
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(int i=1;i<=n;i++){
	for(int j=1;j<=i;j++){
		cin>>a[i][j];
	}
	}
	for(int i=1;i<=n;i++){
	for(int j=1;j<=i;j++){
		if(a[i][j]<=0||a[i][j]<=9){
			ans++;
			}
	}
}
	for(int i=1;i<=n;i++){
	for(int j=1;j<=i;j++){
	cout<<ans;	
	}
}
return 0;
}
