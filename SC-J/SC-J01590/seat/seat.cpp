#include<bits/stdc++.h>
using namespace std;
long long n,m,c[109]={},e=0,g=0,h=0,j=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.in","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	e=c[1];
	sort(c,c+1);
	for(int i=m*n;i>=1;i--){
		if(c[i]==e){
			h=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(i/2==0){
			for(int j=1;j<=n;j++){
				if(i*n-n+j==h){
					cout<<i<<' '<<n-j+1;
					return 0;
				}
			}
		}
		else{
			for(int j=1;j<=n;j++){
				if(i*n-n+j==h){
					cout<<i<<' '<<j;
					return 0;
				}
			}			
		}
	}
}