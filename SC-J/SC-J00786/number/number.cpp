#include<bits/stdc++.h>
using namespace std;
char ch;
int t[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ch=getchar();
	while(ch!='\n'){
		if(ch>='0'&&ch<='9')t[ch-'0']++;
		ch=getchar();
	}
	for(int i=9;i>=0;i--){
		while(t[i]){
			ch='0'+i;
			putchar(ch);
			t[i]--;
		}
	}
	putchar('\n');
	return 0;
}
