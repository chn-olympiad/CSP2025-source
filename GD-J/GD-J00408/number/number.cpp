#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a,s[4],d,f,g;
	cin>>a;
	if(a==1){
		cout<<a;
		return 0;
	}if(a==2){
		cout<<a;
		return 0;
	}if(a==3){
		cout<<a;
		return 0;
	}if(a==4){
		cout<<a;
		return 0;
	}if(a==5){
		cout<<a;
		return 0;
	}if(a==6){
		cout<<a;
		return 0;
	}if(a==7){
		cout<<a;
		return 0;
	}if(a==8){
		cout<<a;
		return 0;
	}if(a==9){
		cout<<a;
		return 0;
	}if(a==0){
		cout<<a;
		return 0;
	}
	d=a/10;
	f=a/100*10;
	cout<<f;
	if(d>f){
		cout<<d<<f;
		return 0;
	}if(d<f){
		cout<<f<<d;
		return 0;
	}if(d==f){
		cout<<d<<f;
		return 0;
	}
}

	
	

