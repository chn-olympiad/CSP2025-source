#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];
int l[20][20];
int a1;
int d=1;
int xx=1,yy=1;
int fy[2]={-1,1};
int cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			a1=a[i];
		} 
	}
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		l[xx][yy]=a[i];
		xx+=fy[d];
		if(cnt==n){
			cnt=0;
			yy++;
			d=abs(d-1);	
			if(d==0){
				xx=n;
			} 
			else if(d==1){
				xx=1;
			}	 
		}
		cnt++;
	}
	for(int i=1;i<=n;i++){		
		for(int j=1;j<=m;j++){
			if(l[i][j]==a1){
				cout<<j<<" "<<i;			
			} 
		}
	}
	return 0;
} 
