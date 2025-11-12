#include<bits/stdc++.h>
using namespace std;
//4 3
//100 99 87 65 79 77 90 91 92 85 83 96
int a[100][100];
int b[105];
int n,m;
int ans,ansx,ansy;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	ans=b[1];
	sort(b,b+n*m+1);
	int p=n*m;
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=1;j<=m;j++){
				a[j][i]=b[p];
				if(b[p]==ans){
					ansx=j,ansy=i;
				}
				p--;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				a[j][i]=b[p];
				if(b[p]==ans){
					ansx=j,ansy=i;
				}
				p--;
			}	
				
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<ansy<<" "<<ansx;
	return 0;
}
