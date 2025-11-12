#include <bits/stdc++.h>
using namespace std;
int a=0,b=0,d=0;
int num[101];
int main (){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a*b;i++){
		cin>>num[i];
	}
	int c=num[1];
	sort(num+1,num+a*b+1);
	for(int i=1;i<=a*b;i++){
		if(num[i]==c){
			d=(a*b)-i+1;
		}
	}
	int e=0;
	if(d%a!=0){
		e=(d/a)+1;
	}else{
		e=(d/a);
	}
	int f=0;
	if(e%2==0){
		f=a-(d-(e-1)*a)+1;
	}else{
		f=d-(e-1)*a;
	}
	
	cout<<e<<" "<<f;
	return 0;
}
