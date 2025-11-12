#include <bits/stdc++.h>
using namespace std;

int x[10000000]={0};

int main(){
	ifstream fin("D:/GD-J03392/number/number.in");
	ofstream fout("D:/GD-J03392/number/number.out");
	string s;
	fin>>s;
	int len=s.size(),n=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			x[n]=s[i]-'0';
			n++;
		}
	}
	sort(x,x+n);
	for(int i=n-1;i>=0;i--){
		fout<<x[i];
	}
	return 0;
}
