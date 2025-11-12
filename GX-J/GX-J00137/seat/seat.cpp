#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1][m+1],c[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	int b=c[1];
	for(int i=1;i<n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(c[i]<c[j]) swap(c[i],c[j]);
		}
	}
	int k=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				a[i][j]=c[k];
				k++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				a[i][j]=c[k];
				k++;
			}
		}
	}
	bool f=0;
	for(int i=1;i<=n;i++){
		if(f) break;
		for(int j=1;j<=m;j++){
			if(a[i][j]==b){
				cout<<i<<" "<<j;
				f=1;
				break;
			}
		}
	}
	return 0;
}
