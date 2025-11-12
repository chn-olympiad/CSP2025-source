#include<bits/stdc++.h> 
using namespace std;
int a[10000],ans,x,y,cnt,b[505][505];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			if(j%2==1){
				b[i][j]=x*(j-1)+i;
			}
			else{
				b[i][j]=x*j-i+1;
			}
		}
	}
	cin>>ans;
	a[1]=ans;
	for(int i=2;i<=x*y;i++){
		cin>>a[i];
	}
	sort(a+1,a+x*y+1);
	for(int i=1;i<=x*y;i++){
		if(a[i]==ans){
			cnt=x*y-i+1;
		}
	}
    for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			if(b[i][j]==cnt){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}