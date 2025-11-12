#include<bits/stdc++.h>
using namespace std;
//转换二进制 
string jz2(int n){
	string s="";
	while(n){
		s+=n%2+'0';
		n/=2;
	}
	string str="";
	for(int i=s.length()-1;i>=0;i--){
		str+=s[i];
	}
	return str;
}
//异或 
string yh(string s){
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]-'0'==1)s[i]='0';
		else s[i]='1';
	}
	return s;
}
//转化十进制
int jz10(string s){
	int n=0;
	string str="";
	for(int i=s.length()-1;i>=0;i--){
		str+=s[i];
	}
	int len=str.length();
	for(int i=0;i<len;i++){
		n+=(str[i]-'0')*pow(2,i);
	}
	return n;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	int k;
	cin>>k;
	int a[500005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	string s[n+1];
	for(int i=1;i<=n;i++){
		if(a[i]==0)s[i]='1';
		else s[i]=yh(jz2(a[i]));
	}
	int sum=0;
	int t=0;
	int l[n+1],r[n+1];
	for(int i=1;i<=n;i++){//right 
		int j;
		for(j=1;j<=i;j++){//left
			sum+=jz10(s[j]);
			if(sum==k){
				l[t]=j;
				r[t]=i;
				t++;
			}
		}	
	}	
	cout<<t;
	return 0;
}
//4 2 2 1 0 3