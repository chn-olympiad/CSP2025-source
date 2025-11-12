#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100],p,q,x,y;
	cin>>n>>m;
	cin>>p;
	q=0;
	for(int i=0;i<n*m-1;i++){
		cin>>a[i];
		if(a[i]>p){
			q++;
		}
	}
	x=q/n+1;
	if(x%2==0){
		y=n-q%n;
	}
	else if(x%2==1){
		y=q%n+1;
	}
	cout<<x<<' '<<y;
}
