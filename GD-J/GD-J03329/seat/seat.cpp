#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[15][15];
	int temp[225];
	for(int i=1;i<=n*m;i++){
		cin>>temp[i];
	}
	int r=temp[1];
	sort(temp+1,temp+n*m+1,cmp);
	int k=1;
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				a[j][i]=temp[k];
				k++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				a[j][i]=temp[k];
				k++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if( r==a[i][j] ){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
} 

