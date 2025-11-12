#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long a[N]={-1};
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	ifstream fin("number.in");
	ofstream fout("number.out");
	string s;
	fin>>s;
	long long k=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<k;i++){
		if(a[i]!=-1)
			fout<<a[i];
	}
	fin.close();
	fout.close();
	return 0;
}
