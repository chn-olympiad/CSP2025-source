#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105][105],image[105][105],fs,gd[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>gd[i];
	}
	fs=gd[1];
	sort(gd+1,gd+1+n*m,cmp);
	int k=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			k++;
			a[i][j]=gd[k];
		}
	}
	for(int i=m,k=1;i>=1;k++,i--){
		for(int j=1;j<=n;j++){
			if(j%2==0){
				image[k][j]=a[j][i];	
			}
			else{
				image[i][j]=a[j][i];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(image[i][j]==fs){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
