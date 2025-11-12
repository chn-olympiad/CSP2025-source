#include<iostream>
#include<cstring>
using namespace std;
int a[11][11],c[101];
int n,m,ans,l,pop;
int main(){	
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
	cin>>c[i];
}
ans=c[1];
for(int i=1;i<=n*m;i++){
	for(int j=1;j<=n*m;j++){
		if(c[i]>c[j]){
			swap(c[i],c[j]);
		}
	}
}
for(int i=1;i<=m;i++){
	if(l%2==0){
	
	for(int j=1;j<=n;j++){
		pop++;
		a[j][i]=c[pop];
		if(c[pop]==ans){
			cout<<i<<" "<<j;
			return 0; 
		}
	}
l=1;	
}
else{
	for(int j=n;j>=1;j--){
			pop++;
		a[j][i]=c[pop];
			if(c[pop]==ans){
			cout<<i<<" "<<j;
			return 0; 
		}
	}
l=0;
}
}
}