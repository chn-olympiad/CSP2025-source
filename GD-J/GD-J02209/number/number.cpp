#include <bits/stdc++.h>
using namespace std;
int num[11]={0,0,0,0,0,0,0,0,0,0,0};
string ans1;
int main(){
	freopen("number.in",'r',stdin);
	freopen("number.out",'w',stdout);
	string s;
	cin>>s;
	int a=s.size();
	for(int i=0;i<a;i++){
		int c=s[i]-'0';
		if(c>=0&&c<=9){
			num[9-c]+=1;
		}
	}
	string e="";
	for(int i=0;i<=9;i++){
		for(int j=0;j<num[i];j++){
			e+='9'-i;
		}
	}
	cout<<e;
	return 0;
} 

