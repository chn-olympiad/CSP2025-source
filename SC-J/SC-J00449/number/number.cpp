#include<bits/stdc++.h>
using namespace std;
int const N=1e6+1;
char S[N];
int len=0;
void read_str(char (&S)[N]){
	char ch=getchar();
	while(!isalpha(ch)&&!isdigit(ch)){
		ch=getchar();
	}
	while(isalpha(ch)||isdigit(ch)){
		if(isdigit(ch)){
			S[len++]=ch;
		}
		ch=getchar();
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read_str(S);
	sort(S,S+len);
	for(int i=len-1;i>=0;i--){
		putchar(S[i]);
	}
	return 0;
}