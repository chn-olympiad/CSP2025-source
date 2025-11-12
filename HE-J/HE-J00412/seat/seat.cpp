#include<bits/stdc++.h>
using namespace std;
int a[122],s[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
			cin>>a[i];
	}
	int ans=a[1];
	for(int j=1;j<=m*n;j++){
		for(int i=1;i<=n*m;i++){
			if(a[i]<a[i+1]){
				swap(a[i],a[i+1]);
			}
		}
	}
	int x=1;
	for(int i=1;i<=m;i++){
		
			if(i%2!=0){
			for(int j=1;j<=n;j++){
					s[i][j]=a[x];
					x++;
			}
		}else{
			for(int j=n;j>0;j--){
					s[i][j]=a[x];
					x++;
			}
		}
	}
	
	for(int c=1;c<=m;c++){
		for(int j=1;j<=n;j++){
			if(s[j][c]==ans){
				cout<<j<<" "<<c;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
