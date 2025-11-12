#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream in("number.in");
	ofstream out("number.out");
	int num[10]={};
	string s;
	in>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]-'0'<10) num[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<num[i];j++){
			out<<i;
		}
	}
	in.close();
	out.close();
	return 0;
}
