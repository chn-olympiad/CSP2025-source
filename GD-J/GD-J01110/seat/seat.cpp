#include<bits/stdc++.h>
using namespace std;
int n,m,nm,c,r,t,cnt=0,a1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	int a[nm],seat[n+1][m+1];
	for(int i=0;i<nm;i++){
		cin>>a[i];
	}
	a1=a[0];
	for(int i=0;i<nm;i++){
		for(int j=0;j<nm-1-i;j++){
			if(a[j]<a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t; 
			}
		}
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			seat[j][i]=a[cnt];
			c=i;
			r=j;
			if(seat[r][c]==a1){
				cout<<c<<" "<<r;
				return 0;
			}
			cnt++;
		}
	}
	return 0;
}
