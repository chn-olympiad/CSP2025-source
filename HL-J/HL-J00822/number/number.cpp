#include<bits/stdc++.h>
using namespace std;
int number[1000000+10];
long long flag=1;
bool cmp(int a,int b){
	if(a!=b){
		return a>b;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	cin.tie(0);
	cout.tie(0);
	long long len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			number[flag]=s[i]-48;
			flag++;
	}
	}
	sort(number+1,number+1+flag,cmp);
	for(int i=1;i<=flag-1;i++){
		printf("%d",number[i]);
	}
	return 0;   
}
