#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[15][15];
int nmp(int a,int b){
	return a>b;	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	int z = n*m;
	for(int i = 1;i<=z;i++){
		cin>>a[i];
	}
	int ans = a[1];
	sort(a+1,a+z+1,nmp);
	int cnt = 0;
	for(int i = 1;i<=m;i++){
		if(i%2==0){
			for(int j = n;j>=1;j--){
				b[j][i] = a[++cnt];
				if(a[cnt]==ans){
					cout<<i<<" "<<j<<endl;
					return 0; 
				}
			}
		}else{
			for(int j = 1;j<=n;j++){
				b[j][i] = a[++cnt];
				if(a[cnt]==ans){
					cout<<i<<" "<<j<<endl;
					return 0; 
				}
			}
		}
	}
	return 0;	
}
