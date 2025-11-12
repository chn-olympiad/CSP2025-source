#include<bits/stdc++.h>
using namespace std;
string s;
int a[10],i=0,j;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[s[i]-48]++;
		}
	}
	for(i=9;i>=0;i--){
		for(j=1;j<=a[i];j++)
		printf("%d",i);
	}
	return 0;
} 
