#include <bits/stdc++.h>
using namespace std;

string s;
char a[1000100];
int i,n;

bool cmp(char c1,char c2){
	if (c1 > c2){
		return true;
	}else{
		return false;
	}
}
int main(){
	cin>>s;
	for (i = 0;i < s.size();i++){
		if ('0' <= s[i] && s[i] <= '9'){
			n++;
			a[n] = s[i];
		}
	}	

	sort(a+1,a+n+1,cmp);
	if (a[1] == '0') cout<<'0'<<endl;
	else{
		for (i = 1;i <= n;i++){
			cout<<a[i];
		}
	}
	return 0;
}
