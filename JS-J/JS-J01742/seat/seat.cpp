#include <bits/stdc++.h>
using namespace std;
int n,m,a1,ai,c=1,r=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;
	for(int i=2;i<=n*m;i++){
		cin>>ai;
		if(ai>=a1){
			if(c%2==1){
				if(r==n){
					c++;
				}
				else{
					r++;
				}
			}
			else{
				if(r==1){
					c++;
				}
				else{
					r--;
				}
			}
		}
	}
	cout<<c<<r;
	return 0;
}
