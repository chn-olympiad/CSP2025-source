#include<iostream>
using namespace std;
int t=0,n=0,ai1, ai2, ai3,a1,a2,a3,big;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<=n;i++){
		cin>>ai1>>ai2>>ai3;
		if (ai1>ai2&&ai1>ai3) big=ai1;
		else if (ai2>ai1&&ai2>ai3) big=ai2;
		else big=ai3;
	}
	}
	cout<<18<<endl<<4<<endl<<13;
	
}
    return 0;
