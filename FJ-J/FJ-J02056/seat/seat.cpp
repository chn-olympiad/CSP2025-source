#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int c=0,x=1,y=1,q=1;
int flagx=1,flagy=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i];
			if(i==1&&j==1){
				c=a[i];
			}
		}
	}
	sort(a+1,a+n*m+1);
	q=n*m;
	for(int i=1;i<=n*m;i++){
		if(x<n&&flagx==1){
			x++;
		}
		else if(x>=1&&flagx==0){
			x--;
		}
		if(x==n){
			flagx=0;
			flagy=1;
		}
		if(x==1){
			flagx=1;
			flagy=1;
		}
		if(y<m&&y>=1&&flagy==1){
			y++;
			flagy=0;
		}
		
		
		if(a[q]==c){
			cout<<x<<' '<<y;
		}
		q--;
	}
	return 0;
}
