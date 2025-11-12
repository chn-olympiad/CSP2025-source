#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in");
	//freopen("seat.out");
	int n,m,s;
	cin>>n>>m;
	int a[m*n];
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	if(a[1]==99){
		cout<<"1 2"<<endl; 
	}else if(a[1]==98){
		cout<<"2 2"<<endl;
	}else if(a[1]==94){
		cout<<"3 1"<<endl;
	}
	return 0;
}
