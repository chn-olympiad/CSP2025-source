#include<bits/stdc++.h>
using namespace std;
char s[1000000];
int o[1000];
bool cmp(int a,int b){
	return a>=b;
}
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	long long n=strlen(s),sum=0,m=0;
	for(int i=0;i<n;i++){
		if(s[i]>=48&&s[i]<=57){
			o[m]=s[i]-'0';
			m++;
		}
	}
	sort(o,o+m,cmp);
	for(int i=0;i<m;i++){
		cout<<o[i];
	}
	return 0;
}