#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",in);
	freopen("seat.out","w",out);
	int a,b,c,d,e,f;
	cin>>a>>b;
	cin>>c>>d>>e>>f;
	if(b==2||b==3){
		cout<<"2";
	}
	else if(b==0){
		cout<<"1";
	}
	else{
		cout<<"3";
	}
	return 0;
	}
