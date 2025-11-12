#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int s[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char in=getchar();
	while((in<'0'||in>'9')&&(in<'a'||in>'z')){
		in=getchar();
	}
	while((in>='0'&&in<='9')||(in>='a'&&in<='z')){
		if(in>='0'&&in<='9'){
			s[in-'0']++;
		}
		in=getchar();
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=s[i];j++){
			putchar(i+'0');
		}
	}
	
	
	
	return 0;
}
