#include<bits/stdc++.h>
using namespace std;
int n,m,a[104],da;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			da++;
		}
	}
	da++;
	int y,x;
	if(da%n==0){
		y=da/n;
		if(y%2==1)x=n;
		else x=1;
	}else{
		y=da/n+1;
		if(y%2==1)x=da%n;
		else x=n-da%n+1;
	}
	cout<<y<<' '<<x;
}
