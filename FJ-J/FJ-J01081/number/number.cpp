#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[10]={0},z=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	gets(s);
	int l=strlen(s);
	for(int i=0;i<l;i++){
		z=s[i]-'0';
		if(z>=0&&z<=9){
			a[z]+=1; 
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
