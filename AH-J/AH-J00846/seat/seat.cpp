#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1],q=1;
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(a[i]>a[j]) swap(a[i],a[j]);
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++) b[j][i]=a[q++];
		}
			
		else{
			for(int j=n;j>=1;j--) b[j][i]=a[q++];
		}
			
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==ans){
				cout<<j<<" "<<i;
				return 0;
			}
			
		}
	}
		
			
	return 0;
}
