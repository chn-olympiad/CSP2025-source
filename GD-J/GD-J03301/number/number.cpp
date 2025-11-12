#include<bits/stdc++.h>
using namespace std;

string s;
char a[1000005];
int p;

ifstream fin("number.in");
ofstream fout("number.out");

int main(){
	fin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			p++;a[p]=s[i];
		}
	}
	sort(a+1,a+p+1,greater<char>());
	for(int i=1;i<=p;i++){
		fout<<a[i];
	}
	fin.close();
	fout.close();
}
