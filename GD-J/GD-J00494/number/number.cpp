#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream in("number.in");
	ofstream out("number.out");
	string s;
	vector<int> a;
	in>>s;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]>='0'&&s[i]<='9'){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end());
	for(int i=a.size()-1;i>=0;i--){
		out<<a[i];
	}
	return 0;
} 
