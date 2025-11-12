#include<bits/stdc++.h>
using namespace std;

int n,m,a[105],b[15][15]; 

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
//	for(int i=1;i<=n*m;i++) cout<<a[i]<<" ";
	sort(a+1,a+n*m+1,greater<int>());
//	for(int i=1;i<=n*m;i++) cout<<a[i]<<" ";
//	cout<<endl;
	int cnt=0;
//	cout<<a[1]<<endl;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				b[j][i]=a[++cnt];
//				cout<<b[j][i]<<" ";
			}
		}else if(i%2==0){
			for(int j=n;j>=1;j--){
				b[j][i]=a[++cnt];
//				cout<<b[j][i]<<" ";
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<b[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==ans){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
} 
//3 3
//94 95 96 97 98 99 100 93 92

