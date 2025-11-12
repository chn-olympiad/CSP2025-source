#include "bits/stdc++.h"
using namespace std;
int a[10000100];
bool cmp(int a,int b){
	return b < a;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	int len =0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[len++] = s[i]-'0';
		}
	}
	sort(a,a+len,cmp);
	for(int i = 0;i<len ;i++){
		cout << a[i];
	}
	cout << endl;
	return 0;
}
