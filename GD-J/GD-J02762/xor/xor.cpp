#include<bits/stdc++.h>
using namespace std;
int a, b, c[100000], d, e;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> a >> b;
	for(int i=0;i<a;i++){
		cin >> c[i];
	}
	for(int i=0;i<a;i++){
		d=c[i];
		for(int j=0;j<a;j++){
			if(d!=c[j]){
				d=d^c[j];
			if(d==b){
				e=max(e, d);
				d=0;
			}
		}
	}
	}
	cout << e;
}
