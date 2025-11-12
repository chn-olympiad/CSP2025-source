#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("number.in");
	ofstream fout("number.out");
	string s;
	int add;
	fin>>s;
	long long a[10]={0};
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			add=s[i]-'0';
			a[add]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			fout<<i;
			a[i]--;
		}
	}
	fin.close();
	fout.close();
} 
