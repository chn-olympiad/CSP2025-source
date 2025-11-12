#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[101],ans;
	cin>>ans;
	a[1]=ans;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[n*m-(i-1)*n-j+1]==ans){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(a[n*m-(i-1)*n+n-j]==ans){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
}
