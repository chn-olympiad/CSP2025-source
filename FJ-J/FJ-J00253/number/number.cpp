#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
#include<cstring>
#include<iomanip>
using namespace std;
string s,s_cout;
int a,number[15],b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	a=s.size();
	for(int i=0;i<a;i++){
		if(s[i]>='0'&&s[i]<='9'){
			number[(int)s[i]]++;
		}
	}
	for(int i=57;i>=47;i--){
		for(int j=number[i];j>=1;j--){
			s_cout+=(char)i;
		}
	}
	cout<<s_cout;
	
	
		
	
	return 0;
}
