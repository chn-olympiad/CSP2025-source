#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	char a[40] = {};
	for(int i = 0;i < s;i++){
		if(a[i] >= '1' && a[i] <= '9'){
			a[i]++;
		}
	}
	for(int i = 0; i < s;i++){
		strcmp a[i];
		if(a[i] > a[i]){
			s++;
		}	
	}
	cout << s;



	return 0;
}
