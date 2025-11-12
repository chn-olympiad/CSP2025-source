#include <bits/stdc++.h>
using namespace std;
const int maxn = 100006;
string s;
int a[maxn];
int cmp(int a1, int a2){
	return a1>a2;
}
int main(){
	freopen("number.in" ,"r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	int k = 1;
	/*for(int i=0; i<s.length(); i++){
		cout<<s[i];
	}*/
	//cout<<endl;
	for (int i=0; i < s.length(); i++){
		if(s[i] == '0') a[k++] = 0;
		if(s[i] == '1') a[k++] = 1;
		if(s[i] == '2') a[k++] = 2;
		if(s[i] == '3') a[k++] = 3;
		if(s[i] == '4') a[k++] = 4;
		if(s[i] == '5') a[k++] = 5;
		if(s[i] == '6') a[k++] = 6;
		if(s[i] == '7') a[k++] = 7;
		if(s[i] == '8') a[k++] = 8;
		if(s[i] == '9') a[k++] = 9;
	}
	/*for(int i=1; i<=k-1; i++){
		cout<<a[i];
	}*/
	//cout<<endl;
	sort(a+1, a+k+1, cmp);
	for(int i=1; i<=k-1; i++){
		cout<<a[i];
	}
	return 0;
}
