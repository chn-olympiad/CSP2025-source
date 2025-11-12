#include<bits/stdc++.h>
using namespace std;
long long a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	if(a<=10){
		cout<<a;
	}else{
		int b=a%10;
		int c=(a-b)/10;
		if(b>c){
			cout<<10*b+c;
		}else{
			cout<<10*c+b;
		} 
	}
	return 0;
}
