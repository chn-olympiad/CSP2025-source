#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	sort(a+1,a+(n*m)+1,greater<int>());
	int x=1;
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				b[i][j]=a[x];
				x++;
			}
		}
		else{
			for(int i=n;i>=1;i--){
				b[i][j]=a[x];
				x++;
			}
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(b[i][j]==ans){
				cout<<j<<" "<<i<<endl;
			}
		}		
	}
	return 0;
}
