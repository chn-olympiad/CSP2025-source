#include<bits/stdc++.h>
using namespace std;
int n,m,csz;
int a[10007]={},b[107][107]={},c[107][107]={};
int e=0;
bool cmp(int x,int y){
	return x>y;
}
void fz(int x){
	for(int i=1;i<=n/2;i++){
		swap(c[x][i],c[x][n-i+1]);
	}
}
int main(){
	freopen("seat.in","r",stdin)
	freopen("seat.out","w",stdout)
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	csz=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==2){
				c[i][j]=a[i*j+n-j];
			}
				
			else c[i][j]=a[i*j+(n-j)*e];
		}
		e++;
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			fz(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]==csz)
				cout<<i<<' '<<n-j+1;
		}
	}
	return 0;
}

