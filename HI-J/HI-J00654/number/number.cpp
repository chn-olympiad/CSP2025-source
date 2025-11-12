#include<bits/stdc++.h>
using namespace std;
long long s[1000000];
long long b[1000000];
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int main(){
	long long a=0,d=0;
	while(cin>>s[a]){
		cin>>s[a++]; 
	}
	for (long long i=0;i<=a;i++){
		if(s[i]==1){
			b[d++]=s[i];
		}
		else if(s[i]==2){
			b[d++]=s[i];
		}
		else if(s[i]==3){
			b[d++]=s[i];
		}
		else if(s[i]==4){
			b[d++]=s[i];
		}
		else if(s[i]==5){
			b[d++]=s[i];
		}
		else if(s[i]==6){
			b[d++]=s[i];
		}
		else if(s[i]==7){
			b[d++]=s[i];
		}
		else if(s[i]==8){
			b[d++]=s[i];
		}
		else if(s[i]==9){
			b[d++]=s[i];
		}
	}
	sort(b,b+a);
	cout<<b;
	return 0;
}
