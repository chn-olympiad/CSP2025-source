#include <bits/stdc++.h>
using namespace std;

int num[10] = {};
string a = "";
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	
	for(int i = 0;i<=a.length();i++){
		if(a[i] == '0') num[0]++;
		if(a[i] == '1') num[1]++;
		if(a[i] == '2') num[2]++;
		if(a[i] == '3') num[3]++;
		if(a[i] == '4') num[4]++;
		if(a[i] == '5') num[5]++;
		if(a[i] == '6') num[6]++;
		if(a[i] == '7') num[7]++;
		if(a[i] == '8') num[8]++;
		if(a[i] == '9') num[9]++;
	}
	
	for(int i = 9;i>=0;i--){
		while(num[i]>0){
			cout << i;
			num[i]--;
		}
	}
	return 0;
} 
