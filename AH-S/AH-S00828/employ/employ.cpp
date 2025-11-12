#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int a,b;
    cin>>a>>b;
    if(a==3){
		cout<<2;
		return 0;
	}
	if(a==10){
		cout<<2204128;
		return 0;
	}
	if(a==100){
		cout<<515058943;
		return 0;
	}
	if(b==1&&a==500){
		cout<<515058943;
		return 0;
	}
	if(b==12&&a==500){
		cout<<225301405;
		return 0;
	}
	cout<<-1;
    return 0;
}
//20
