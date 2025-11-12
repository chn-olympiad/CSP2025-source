#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ifstream fin("number.in");
	ofstream fout("number.out");
	string s;
	fin>>s;
	int n=s.size();int a[10]={0};
	for(int i=0;i<n;i++){
		while(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
			i++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			fout<<i;
		}
	}
	return 0;
}
