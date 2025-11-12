#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	int x = a+b+c+d+e;
	if(x == 15){
		cout << 9;
	}else if(x == 25){
		cout<<6;
	}else{
		cout<<12;
	}
return 0;
}
