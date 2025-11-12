#include<bits/stdc++.h>
using namespace std;

string s;
long long a[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s ;
	int i=0;
	while(s[i]>='0' && s[i]<='9' || s[i]>='a' && s[i]<='z'){
		if (s[i]>='0' && s[i]<='9'){
			a[(s[i]-'0')]++;
//			cout << s[i]-'0' << " "<<i<< endl ;
		}
		i++;
	}
	for (int j=9;j>=0;j--){
		for (int k=1;k<=a[j];k++){
			cout << j ;
		}
	}
	return 0;
}