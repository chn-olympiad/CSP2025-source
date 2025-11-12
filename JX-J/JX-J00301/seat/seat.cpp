#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],asd[105],w,y=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1) w=a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		asd[n*m-i+1]=a[i];
	}
	for(int i=1;i<=m;i++){
		if(y%2==1){
			for(int j=1;j<=n;j++){
				if(asd[n*(y-1)+j]==w){
					cout<<y<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(asd[n*y-j+1]==w){
					cout<<y<<" "<<j;
					return 0;
				}
			}
		}
		y++;
	}
}
