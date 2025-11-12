#include <bits/stdc++.h>
using namespace std;
int MAXN=100000;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[MAXN];
	bool b=true;
	int i=-1;
	getline(cin,s);
	for(int n=0;n<s.length();n++){
		if(s.at(n)=='0'||s.at(n)=='1'||s.at(n)=='2'||s.at(n)=='3'||s.at(n)=='4'||s.at(n)=='5'||s.at(n)=='6'||s.at(n)=='7'||s.at(n)=='8'||s.at(n)=='9'){
			a[++i]=int(s.at(n))-48;
		}
	}
	while(b){
		b=false;
		for(int n=0;n<i;n++){
			int connect;
			if(a[n]<a[n+1]){
				connect=a[n];
				a[n]=a[n+1];
				a[n+1]=connect;
				b=true;
			}
		}
	}
	for(int n=0;n<=i;n++){
		cout << a[n];
	}
	return 0;
}
