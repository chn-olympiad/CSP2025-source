#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m,a[N],x,y,id=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			id++;
		}
	}
	x=id/n;
	if(id%n!=0){
		x++;
	}
	if(x%2==1){
		if(id%n==0){
			y=n;
		}
		else{
			y=id%n;
		}
	}
	else{
		if(id%n==0){
			y=1;
		}else{
			y=n-(id%n)+1;
		}
	}
	cout<<x<<' '<<y;
	return 0;
}
