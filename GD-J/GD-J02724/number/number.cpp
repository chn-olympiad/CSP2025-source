#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
string s; 
int n[N];
int main(){
	ifstream fin("number.in");
	ofstream fout("number.out");
	fin>>s;
	int w=0,l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>=48&&s[i]<=58) {
			n[w]=s[i]-'0';
			w++;
		}		
	}
	sort(n,n+w);
	for(int i=w-1;i>=0;i--) fout<<n[i];
	return 0;
} 
