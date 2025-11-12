#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in",r,stdin);
	freopen("seat.out",w,stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++)cin>>a[i];
	int x=a[0];
	sort(a,a+n*m);
	reverse(a,a+n*m);
	int b[n][m],xx=0,yy=0;
	int c=0;
	for(int i=0;i<n*m;i++){
		b[xx][yy]=a[i];
		if(yy%2==0){
			xx++;
			if(xx>n-1)yy++,xx--;
		}
		else if(yy%2==1){
			xx--;
			if(xx<0)yy++,xx++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(b[i][j]==x){
				cout<<j+1<<" "<<i+1;
				return 0;
			}
		}
	}
	return 0;
} 
