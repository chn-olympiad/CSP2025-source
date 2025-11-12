#include <bits/stdc++.h>
using namespace std;
string s;
int b[1000100];
double cmp(int a,int b){
	return a > b;
}
int main(){
	freopen( "number.in" , "r" , stdin);
	freopen( "number.out" , "w" , stdout);
	cin>>s;
	int len=s.length();
	int c=1;
	for(int i=0 ; i<len ; i++){
		if(s[i]>='0' && s[i]<='9'){
			b[c]=int(s[i]-'0');
			c++;			
		}
	}
	sort(b+1,b+c,cmp);
	for(int i=1 ; i<c ; i++){
		cout<<b[i];
	}
	return 0;
}
