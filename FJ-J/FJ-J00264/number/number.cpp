#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int t[10];
char s[N];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);int len=strlen(s+1);
	for(int i=1;i<=len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			++t[s[i]-'0'];
		}
	}
	for(int i=9;~i;i--){
		for(int j=1;j<=t[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}
