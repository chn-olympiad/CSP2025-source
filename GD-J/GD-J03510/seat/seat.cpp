#include<bits/stdc++.h>
using namespace std;
int m,n,a1;
int a[105],b[12][12];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	a1=a[1];
	//≈≈–Ú
	int mn=1;
	while (mn<=m*n){
		int maxn=-1,maxp=-1;
		for(int i=mn;i<=m*n;i++){
			if(a[i]>maxn){
				maxn=a[i];
				maxp=i;
			}
		}
		int r=a[mn];
		a[mn]=maxn;
		a[maxp]=r;
		mn++;
	}
	//for(int i=1;i<=m*n;i++){
	//	cout<<a[i]<<" ";
	//}
	//ÃÓ≥‰ 
	int d=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				b[j][i]=a[d];
				d++;
			}
		}else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[d];
				d++;
			}
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==a1){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
