#include<bits/stdc++.h>
const int N=1e6+5;
int a[N];
char ch;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ch=getchar();
	while(ch!='\n'){
		if(ch<='9'&&ch>='0')a[ch-'0']++;
		ch=getchar();
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			putchar(i+'0');
		}
	}
}