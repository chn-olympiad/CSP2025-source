#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
char c[N];
int a[10];
int main(){
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	for(int i=0;i<10;i++)a[i]=0;
	for(int i=0;i<N;i++)c[i]='a';
	scanf("%s",c);
	for(int i=0;i<N;i++){
		if(c[i]<='9'&&c[i]>='0'){
			a[c[i]-'0']++;
		}	
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			char b='0'+i;
			printf("%c",b);
		}
	}
	return 0;
}
