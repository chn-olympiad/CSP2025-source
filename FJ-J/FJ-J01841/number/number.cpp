#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("number.in");
	ofstream fout("number.out");
	string s;
	fin>>s;
	int l=s.length();
	char n[l];
	int size=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[size]=s[i];
			size++;
		}
	}
	sort(n,n+size);
	for(int i=size-1;i>=0;i--){
		fout<<n[i];
	}
	return 0;
}
