#include<bits/stdc++.h>
using namespace std;
int c,r; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>c>>r;
	int a;
	cin>>a;
	int c1 = 1,r1 = 1;
	for(int i = 0;i<c*r-1;++i){
		int x;
		cin>>x;
		if(x>a){
			if(c1%2==1){
				r1++;
				if(r1>r){
					c1++;
					r1 = r;
				}
			}
			else{
				r1--;
				if(r1<1){
					r1 = 1;
					c1++;
				}
			}
		}
	}
	cout<<c1<<" "<<r1;
	return 0;
}
