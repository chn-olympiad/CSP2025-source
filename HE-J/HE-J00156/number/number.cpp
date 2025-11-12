#include<bits/stdc++.h>
using namespace std;
string s;
int n=0,x=0;
int a[100];
int main(){
	freopen("number.in ","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=100;i++){
		cin>>s;
		if(s==1||s==2||s==3||s==4||s==5||s==6||s==7||s==8||s==9){
			a+=s;
		}
	}
	x=a[1];
	for(int i=1;i<=a;i++){
		if(i>x){
			x=1;
		}
		cout<<x;
	}
	return 0;
}
