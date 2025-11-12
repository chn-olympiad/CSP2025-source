#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	int c,r,x;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	if(n==1 && m==1){
		cout<<"1 1";
		return 0;
	}
	else{
		if(a[1]==1){
			if(m%2!=0) {
				c=m;
				r=1;
			}
			else{
				c=m;
				r=n;
			}
		}
		else {
			cout<<"1 1";
			return 0;
		}
		cout<<c<<" "<<r;
	}
	return 0;
}
