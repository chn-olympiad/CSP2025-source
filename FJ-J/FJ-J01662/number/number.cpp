#include <bits/stdc++.h>
using namespace std;
ifstream fin("number.in");
ofstream fout("number.out");
int main(){
	string a;int b[10]={0};
	fin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]<='9' and a[i]>='0'){
			b[int(a[i]-'0')]+=1;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<b[i];j++) {
			fout<<i;
		}
	}
	return 0; 
}
