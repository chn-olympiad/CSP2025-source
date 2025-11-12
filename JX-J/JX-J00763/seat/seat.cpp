#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,box=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int ans=a[1];
	int b=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(box%2!=0){
		for(int j=1;j<=n;j++){
			if(a[b]==ans){
				cout<<i<<" "<<j;
				i=m;
				j=n;
				break;
			}
			b++;
		}
	}else{
		for(int j=n;j>=1;j--){
			if(a[b]==ans){
				cout<<j<<" "<<i;
				break;
			}
			b++;
		}
	}
	
	box++;
}
	return 0;
}
