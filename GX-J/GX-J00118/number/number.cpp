#include<bits/stdc++.h>
using namespace std;
int a[10]={0};

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	char c;
	while((c=getchar())!='\n'){
		if(c>='0'&&c<='9'){
			a[c-'0']++;
		}
	}
	
	for(int i=9;i>=0;i--){
		while(a[i]--)putchar(i+'0');
	}
	
	return 0;
}
