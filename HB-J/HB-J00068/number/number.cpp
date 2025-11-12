#include <bits/stdc++.h>
using namespace std;
ifstream fin("number.cpp");
ofstream fout("number.cpp");
string s;
int a[100005],b=0;
int main(){
	fin>>s;
	for (int i=0;i<s.size();i++){
		if (s[i]>='0'&&s[i]<='9'){
			a[b]=s[i]-'0';
			b++;
		}
	}
	sort(a,a+b);
	for (int i=b-1;i>=0;i--) fout<<a[i];
	return 0;
}			
