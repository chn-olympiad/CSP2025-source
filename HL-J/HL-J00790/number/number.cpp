#include<bits/stdc++.h>
using namespace std;

int num[10]{0};

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	int i,j;
	char s;
	
	while(cin>>s){
		if(s>='1' && s<='9'){
			num[(int)s-48]++;
		}
	}
	
	for(i=9;i>=0;i--){
		for(j=1;j<=num[i];j++){
			cout<<i;
		}
	}
	
	return 0;
}
