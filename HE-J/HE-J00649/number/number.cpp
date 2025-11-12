#include <iostream>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a,x,y;
	cin>>a;
	x=a/10;
	y=a%10;
	if(x==0){
		cout<<y;
	}else{
		if(x>y){
			cout<<x<<y;
		}else{
			cout<<y<<x;
		}
	}
} 
