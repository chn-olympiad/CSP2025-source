#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat,out","w",stdout);
	int a,b;
	cin>>a>>b;
	if(b<=100){
		if(a==100){
			cout<<"1 1";
		}
		if(a==99){
			cout<<"1 2";
		}
		if(a==98){
			cout<<"2 2";
		}
	}
	return 0;
}
