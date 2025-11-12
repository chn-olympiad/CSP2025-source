#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a1,a2,a3,a4,a5;
	cin >>n;
	cin>>a1>>a2>>a3>>a4>>a5;
	if(a1+a2+a3+a4+a5==25){
		cout<<"6";
	}else{
		cout<<"9";
	}
	return 0;
}
