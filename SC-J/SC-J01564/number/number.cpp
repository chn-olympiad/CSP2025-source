#include<bits/stdc++.h>
using namespace std;

bool tmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a;
	int s[1005],cmp=0;
	while(cin>>a){
		if(a-"0">=0&&a-"0"<=9){
			s[cmp]=a-"0";
			cmp++;
		}
	}
	sort(s,s+cmp,tmp);
	for(int i=0;i<cmp;i++){
		cout<<s[i];
	}
	
	return 0;
} 