#include<bits/stdc++.h>
using namespace std;
int a[11][10];
int b[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out ","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	int k=1;
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			a[i][j]=k;
			k++;
		}	
	}
	n=n*m;
	int xr=0,r=0;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	xr=b[1];
	sort(b+1,b+1+n);
	int s=0;
	for(int i=n;i>=1;i--){
		s++;
		if(b[i]==xr){
			r=s;
		}
	}
	int h=0,l=0;
	for(int j=1;j<=11;j++){
		for(int i=1;i<=11;i++){
			if(a[i][j]==r){
				h=i;
				l=j;
			}
		}	
	}
	cout<<l<<" "<<h;
	return 0;
}
