#include<bits/stdc++.h>
using namespace std;
char c[1000002];
int n,m[12];
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	while((scanf("%c",&c[++n]))!=EOF) {
		if(c[n]-'0'>=0 && c[n]-'0'<=9) m[c[n]-'0']++;
	}
	for(int j=9;j>=0;j--) 
		for(int i=1;i<=m[j];i++){
			printf("%d",j);
		}
	return 0;
}
