#include<bits/stdc++.h>
using namespace std;
int b[1000010],s=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","a",stdout);
	char a;
	while(cin>>a){
		if(a>='0'&&a<='9'){
			b[s]=(int)a-'0';
			s++;
		} 
	}
	sort(b,b+s);
	for(int i=s-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
} 
