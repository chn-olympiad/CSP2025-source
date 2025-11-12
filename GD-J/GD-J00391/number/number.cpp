#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
  
int s[N];
string a;
int b=1;

int main(){
	fre("number.in ","r","stdin");
	fre("number.out","w","stdout");
	cin>>a;
	int len=a.length();
	for(int i=1;i<=len;++i){
		if(a[i]!='0' && a[i]!='1' && a[i]!='2' && a[i]!='3' &&a[i]!='4' && a[i]!='5' && a[i]!='6' && a[i]!='7' && a[i]!='8' && a[i]!='9'){
			continue;
		}else{
			a[i]==' ';
		}
	}
	cout<<a<<endl;
	for(int i=1;i<=len;++i){
		if(a[i]!=' '){
			s[i]=a[i]+'0';
		}else{
			continue;
		}	
	}
	sort(s+1,s+len+1);
	for(int i=1;i<=len;++i){
		cout<<s[i];
	}
	
	return 0;
} 
