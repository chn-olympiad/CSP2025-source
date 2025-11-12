#include <bits/stdc++.h>
using namespace std;
int a[105],n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int p=a[0];
	sort(a,a+n*m);
	int y=0;
	for(int i=n*m-1;i>=0;i--){
		y=y+1;
		if(a[i]==p){
			break;
	}
	}
	int j=y/n;
	if(y%n!=0){
		j=j+1;
	} 
	int k=y%n;
	if(y%n==0){
       k=n;
   }
	cout<<j<<" "<<k;
	return 0;
}
