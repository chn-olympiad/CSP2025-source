#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100][100],b[10005],ans=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	ans=b[0];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	} 
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=b[j];
			if(a[i][j]==ans){
				cout<<a[i][j];
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
