#include<bits/stdc++.h>
using namespace std;
int n,m,a[150],f;
bool cmp(int x,int y){
	return x>y;
}
int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		if(j%2==1){
			for(int i=(j-1)*n+1;i<=(j-1)*n+n;i++){
				if(a[i]==f){
					cout<<j<<" "<<(i-1)%n+1;
					return 0;
				} 
			}
		}
		else{
			for(int i=n+(j-1)*n;i>=(j-1)*n+1;i--){
				if(a[i]==f){
					cout<<j<<" "<<(i-1)%n+1;
					return 0;
				} 
			}
		}
	}

	return 0;
}
