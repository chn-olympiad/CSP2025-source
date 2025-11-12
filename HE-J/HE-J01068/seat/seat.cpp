#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,g=1,h=2;
	cin>>n>>m;
	int a[n*m];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	if(a[1]<a[2] && a[1]<a[3] && a[1]<a[4]){
		cout<<g<<g;
	}else if(a[1]>a[2] && a[1]<a[3] && a[1]<a[4]){
		cout<<g<<h;
	}else if(a[1]>a[2] && a[1]>a[3] && a[1]<a[4]){
		cout<<h<<h;
	}else if(a[1]>a[2] && a[1]>a[3] && a[1]>a[4]){
		cout<<h<<g;
	}
	return 0;
}
