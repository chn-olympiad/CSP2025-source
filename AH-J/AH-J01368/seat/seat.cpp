#include<bits/stdc++.h>
using namespace std;
int m,n,a[20][20],t,x=1,y=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1][1];
    for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
		    cin>>a[i][j];
		    if(a[i][j]>a[1][1])t++;
		}
	}
	for(int i=1;i<=t;i++){
		if(y%2==1){
			if(x<n)x++;
			else y++;
		}
		else if(y%2==0){
			if(x>1)x--;
			else y++;
		}
	}
	cout<<y<<" "<<x;
	return 0;
	
}
