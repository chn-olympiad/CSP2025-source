#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	string s;
	long long a=0,cnt=0,sum=0,c[10000000],j=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
	if(s[i]=='9'){
	a=a*10+9;
	}if(s[i]=='8'){
	a=a*10+8;
	}if(s[i]=='7'){
	a=a*10+7;
	}if(s[i]=='6'){
	a=a*10+6;
	}if(s[i]=='5'){
	a=a*10+5;
	}if(s[i]=='4'){
	a=a*10+4;
	}if(s[i]=='3'){
	a=a*10+3;
	}if(s[i]=='2'){
	a=a*10+2;
	}if(s[i]=='1'){
	a=a*10+1;
	}if(s[i]=='0'){
	cnt++;
	}
	}
	while(a){
	c[j]=a/1%10;
	sum++;
	j++;
	a=a/10;
	}
	sort(c+0,c+sum,cmp);
	for(int i=0;i<sum;i++){
	cout<<c[i];
	}
	for(int i=1;i<=cnt;i++){
		cout<<0;
	}
return 0;
} 
