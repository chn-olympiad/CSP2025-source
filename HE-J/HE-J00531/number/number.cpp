#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int s1[1000000];
string s;
int main(){
freopen("number.in","r","std");
int j1=0;
cin>>s;
for (long long i=0;i<sizeof(s);i++){
	char a=s[i];
	if (a=='0' || a=='1' || a=='2' || a=='3' || a=='4' || a=='5' || a=='6' || a=='7' || a=='8' || a=='9'){
		s1[j1]=a-48;
		j1++;
	}
}
for (long long j=0;j<j1;j++){
	for (long long i=0;i<j1;i++){
		if (s1[i]<s1[i+1]){
			int a,b,c;
			a=s1[i];
			b=s1[i+1];
			c=a;
			a=b;
			b=c;
			s1[i]=a;
			s1[i+1]=b;
		}
	}
}
for (long long i=0;i<j1;i++){
	cout<<s1[i];
}
freopen("number.out","w","std");
return 0;
}
