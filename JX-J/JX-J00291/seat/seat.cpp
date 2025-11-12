#include<bits/stdc++.h>
using namespace std;
int a[105],ar,n,m,zw;
void mop(int a[105],int n){
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
			if(a[i]<a[i+1]&&i!=n*m) swap(a[i],a[i+1]);
		}
	}
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m>>a[0];
	ar=a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	mop(a,n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==ar){
			zw=i+1;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			zw--;
			if(zw==0){
				cout<<i<<" "<<j;
			}
		}
		i++;
		for(int j=n;j>=1;j--){
			zw--;
			if(zw==0){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
