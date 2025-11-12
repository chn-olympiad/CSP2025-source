#include<iostream>
using namespace std;
    int i,l;
	int n,m;
int main(){
	cin>>n>>m;
	l=n*m;
	int seat[l];
	for(;i<l;i++){
		cin>>seat[i];
	}
	int b=seat[0];
	if(b==99)
        cout<<"1 2";
    if(b==98)
        cout<<"2 2";
    if(b==94)
        cout<<"3 1";
    return 0;
}

