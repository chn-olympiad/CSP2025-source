#include<bits/stdc++.h>
using namespace std;
int n,m;
int seat[500];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x = n*m;
	for(int i = 1;i<=x;i++){
		cin>>seat[i];
	}
	int a = seat[1];
	sort(seat+1,seat+x+1,greater<int>());
	int c,r;
	for(int i = 1;i<=x;i++){
		if(seat[i] == a){
			if(i%n==0){
				r = i/n;
				if(r%2 == 0){
					c = 1;
				}else{
					c = n;
				}
			}else{
				r = (i+n)/n;
				if(r%2 == 0){
					int y = i%n;
					c = n+1-y;
				}else{
					c = i%n;
				}
			}
		}
	}
	cout<<r<<" "<<c;
	return 0;
}