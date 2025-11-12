#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin>>s;
	vector<short> a;
	for(char i : s){
		if (isdigit(i))
			a.push_back(i-'0');
	}
	int p[10]={};
	for(short n : a){
		p[n]++;
	}

	string o;
	for(int i=9;i>=0;i--){
		for(int j=0;j<p[i];j++){
			o.push_back(i+'0');
		}
	}
	cout<<o;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}