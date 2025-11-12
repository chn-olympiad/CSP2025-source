#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	ifstream fin("number.in");
	ofstream fout("number.out");
	string s;
	fin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			a[s[i]-'0']++;
			}
		}
	for(int i=0;i<a[9];i++)fout<<9;
	for(int i=0;i<a[8];i++)fout<<8;
	for(int i=0;i<a[7];i++)fout<<7;
	for(int i=0;i<a[6];i++)fout<<6;
	for(int i=0;i<a[5];i++)fout<<5;
	for(int i=0;i<a[4];i++)fout<<4;
	for(int i=0;i<a[3];i++)fout<<3;
	for(int i=0;i<a[2];i++)fout<<2;
	for(int i=0;i<a[1];i++)fout<<1;
	for(int i=0;i<a[0];i++)fout<<0;
	return 0;
}
