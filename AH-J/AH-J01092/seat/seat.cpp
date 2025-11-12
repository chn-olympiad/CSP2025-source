#include<bits/stdc++.h>
using namespace std;
int a[1000],b[200][200],c[1000];
bool cmp(int x,int y){
    return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k=1;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
		c[i]=a[i];
	}
	sort(a+1,a+1+n*m,cmp);

	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				b[j][i]=a[k];
				k++;
			}
		}else{
			for(int j=n;j>=1;j--){
				b[j][i]=a[k];
				k++;
			}
		}
	}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		if(b[i][j]==c[1]){
			cout<<j<<" "<<i;
		}
}
	}	
	return 0;
}
