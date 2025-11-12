#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int sum,len=0,a[35],b[35];
	cin >> s;
	for(char i;i < s;i++){
		if(i >= '0' && i<='9'){
			a[0] += i;
			len+=1;
		}
	}
	for(int j = 0;j<=len;j++){
		sum += a[j];
	}
	cout << sum;
	return 0;
} 
