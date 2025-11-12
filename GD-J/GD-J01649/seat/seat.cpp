#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r"stdin);
	freopen("seat.out","w"stdout);
	int n,m;
	cin>>n>>m;
	int a[114],nm=n*m;
	int xr;
	for(int i=1;i<=nm;i++){
		cin>>a[i];
	}
	xr=a[1];
	int x=1;
	for(int i;i<=nm;i++){
		if(xr<a[i]){
			x++;
		}
	}
	int c,r;
	cout<<x/m+1<<" ";
	if(x%2==1){
		cout<<x%m;
	}
	else{
		cout<<m-x%m;
	}
}
