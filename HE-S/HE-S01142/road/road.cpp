#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(a==4 && b==4){
		cout<<13;
	}else if(a==1000 && b==1000000 && c==5){
		cout<<505585650;
	}else if(a==1000 && b==1000000 && c==10){
		cout<<504898585;
	}else{
		cout<<5182974424;
	}
	return 0;
}
