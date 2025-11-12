#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a;
	cin >> a;
	int text = a;
	int textt = a;
	text%=10;
	text*=10;
	textt/=10;
	text=text+textt;
	if(text>a){
		cout << text << endl;
	}
	else{
		cout << a << endl;
	}
	return 0;
}
