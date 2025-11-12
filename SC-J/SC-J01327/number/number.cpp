#include<bits/stdc++.h >
using namespace std;
string a;
int s[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin >>a;
	for (long long i=0;i<a.size();i++){
		if (a[i]<='9'&&a[i]>='0'){
			s[a[i]-'0']++;
		}
	}
	bool ss=true;
	for (int i=9;i>=0;i--){
		if (s[i]!=0)ss=false;
		for (int j=0;j<s[i];j++){
			cout <<i;
		}
	}
	if(ss){
		cout <<"0";
	}
	return 0;
}