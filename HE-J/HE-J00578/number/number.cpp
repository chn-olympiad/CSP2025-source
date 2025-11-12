#include <bits/stdc++.h>
using namespace std;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(1){
		int ch = getchar();
		if(ch==EOF||ch=='\n') break;
		if(!(('A'<=ch&&ch<='Z')||('a'<=ch&&ch<='z')||('0'<=ch&&ch<='9'))) break;
		if('0'<=ch&&ch<='9') a[ch-'0']++;
	}
	int n = 10;
	while(n--){
		while(a[n]--){
			cout<<n;
		}
	}
	return 0;
} 
