#include <bits/stdc++.h>
using namespace std;
int cnt=0,tong[15];
string s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			tong[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=tong[i];j++){
			cout << i;
		}
	}
	return 0;
}
