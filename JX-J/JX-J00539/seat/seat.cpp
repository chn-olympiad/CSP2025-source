#include<bits/stdc++.h>
using namespace std;
int c[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	int f=1;
	cin >> a >> b;
	for(int i=1;i<=a*b;i++){
		cin >> c[i];
	}
	for(int i=2;i<=a*b;i++){
		if(c[i]>=c[1]){
			f++;
		}
	}
	int d=2*a;
	if(f%d==0){
		cout << f/a << " 1";
	}
	else if(f%a==0){
		cout << f/a << " " << a;
	}
	else if(f%d>a){
		cout << f/a+1 << " " << a-f%a+1;
	}
	else{
		cout << f/a+1 << " " << f%a;
	}
	return 0;
}
