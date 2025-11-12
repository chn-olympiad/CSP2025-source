#include<bits/stdc++.h>
using namespace std;
int c,r,x,a[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>c>>r;
	for(int i=1;i<=c*r;i++){
		cin>>a[i];
	}
	x=a[0];
	sort(a[0],a[c*r-1]);
	for(int i=1;i<=c*r;i++){
		if(a[i-1]==x){
			if(c>=i/r) {
				cout<<i;
			}
			else if(c<i/r) {
				cout<<r/i;
			}
			if(r>=i/c) {
				cout<<i;
			}
			else if(r<i/c) {
				cout<<c/i;
			}
		}
	}
	return 0;
}
