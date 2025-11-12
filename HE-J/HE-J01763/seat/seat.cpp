#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m];
	for (int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int v=1;
	for (int i=1;i<=n*m;i++){
		if (a[0]<a[i])v++;
	}
	int x=v/n;
	int y=v%n;
	if (y!=0){
		if (x%2!=0){
			y=n-y+1;
			x++;
			cout<<x<<' '<<y;
		}
		if (x%2==0){
			x++;
			cout<<x<<' '<<y;
		}
	}
	else{
		y=n;
		cout<<x<<' '<<y;
	}
	return 0;
}




