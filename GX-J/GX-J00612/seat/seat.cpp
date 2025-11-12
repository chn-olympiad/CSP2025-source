#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],k,b[100][100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
		cin>>a[i];
}	
k=a[1];
for(int i=1;i<=n*m;i++){
	for(int j=i+1;j<=n*m;j++){
		if(a[j]<a[j+1]){
			swap(a[j],a[j+1]);
		}
	}
}
int x=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
			b[i][j]=a[x];
			x++;
			}
		}	
		if(i%2==0){
			for(int j=n;j>=1;j--){
			b[i][j]=a[x];
			x++;
			}	
		}	
		
}
for(int i=1;i<=m;i++){
	for(int j=1;j<=n;j++){
		if(b[i][j]==k){
			cout<<m<<" "<<n;
			return 0;
	}
}
}
	return 0;
}
