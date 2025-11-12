#include<iostream>
using namespace std;
int main(){
	int l;
	int h;
	int xm;
	int dy;
	int de;
	int ds;
	cin>>l;
	cin>>h;
	cin>>xm;
	cin>>dy;
	cin>>de;
	cin>>ds;
	if(xm>dy>de>ds){
		cout<<l+h;
	}
	return 0;
}
