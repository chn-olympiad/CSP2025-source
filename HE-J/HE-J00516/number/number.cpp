#include<bits/stdc++.h>
using namespace std;
#define ii long long
char s[1000000];
bool cmp(ii a,ii b){
	return (a-'0')>(b-'0');
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >>s;
	ii ss[strlen(s)+1] = {};
	ii iz=0;
	for(ii i=0;i<strlen(s);i++){
		if(s[i]>='0' && s[i]<='9'){
			ss[iz++] = s[i]-'0';
		} 
	}
	sort(ss,ss+iz,cmp);
	for(ii i=0;i<iz;i++){
		cout << ss[i];
	}
	return 0;
} 
