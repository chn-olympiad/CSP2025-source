#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c=1,r=1,b,d;
	cin>>n>>m;
	cin>>b;
	for(int i=1;i<n*m;i++){
		cin>>d;
		if(c%2==1){
			if(d>b){
				r++;
				if(r>n){
					c++;
					r=n;
				}
			}
		}else{
			if(d>b){
				r--;
				if(r<1){
					c++;
					r=1;
				}
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
