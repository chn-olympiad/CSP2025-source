#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>> n;
	int len = n.length(),o = 0;
	for(int i = 0;i < len;i++){
		if(n[i] >= '0' && n[i] <= '9'){
			a[(int)(n[i]-'0')]++;
		}
	}
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= a[i];j++){
			cout<< i;
		}
	}
	return 0;
}
