#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("number.in");
	ofstream fout("number.out");
	
	string s,aa = "0123456789abcdefghijklmnopqrstuvwxyz";
	char a;
	long long l = 0,x[10000005];
	stringstream ss;
	fin >> s;
	for(long long i = 0; i < s.length(); i++){
		ss << s[i];
		ss >> a;
		if (a < 90){
			x[l] = a-48;
			l++;
		}
	}
	sort(x,x+l);
	for(long long i = l-1; i >= 0; i--){
		fout << x[i];
	}
	
	fin.close();
	fout.close();
	
	return 0;
}
