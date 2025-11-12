#include<bits/stdc++.h>
using namespace std;
long long n[10];
char a;
int i,j;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a){
		if(a>='0'&&a<='9'){
			n[a-'0']++;
		}
	}
	for(i=9;i>=1;i--){
		for(j=0;j<n[i];j++) cout<<i;
	}
	return 0;
} 
