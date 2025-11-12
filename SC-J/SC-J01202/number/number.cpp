#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
	cin>>a;
	if(a<=9){
		cout<<a;
	}else{
		b=a%10;
		c=a/10%10;
		cout<<max(10*b+c,10*c+b);
	}
	return 0;
}