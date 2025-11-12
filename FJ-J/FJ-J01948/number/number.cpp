#include<bits/stdc++.h>
using namespace std;

char s;
int n[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>s){
		if(s>='0' && s<='9')
			n[s-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=n[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
