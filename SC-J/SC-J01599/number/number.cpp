#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

int main(){
	fre("number");
	string s;
	int a[10]={};
	cin>>s;
	for(char x:s){
		if(x>='0'&&x<='9'){
			a[x-'0']++;
		}
	}
	for(int i=9;i>=0;i--)for(int j=0;j<a[i];j++)cout<<i;
	return 0;
}