#include<bits/stdc++.h>
using namespace std;
int a[12][12];
int b[110];
int cmp(int p,int q){
	if(p>q){
		return 1;
	}
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,weizhi;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%ld",&b[i]); 
	}
	int xr=b[1];
	int lklk=1;
	sort(b+1,b+m*n+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>0;j--){
				a[i][j]=b[lklk];
				lklk++;
			}
		}
		else{
			for(int j=1;j<=n;j++){
				a[i][j]=b[lklk];
				lklk++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==xr){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	return 0;
}
