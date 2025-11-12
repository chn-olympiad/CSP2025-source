#include <bits/stdc++.h>
using namespace std;

int n,a[11];
char s[1000010];

int main(){
	scanf("%s",s + 1);
	n = strlen(s + 1);
	for(int i = 1;i <= n;i++) if(s[i] >= '0' && s[i] <= '9') ++a[s[i] - '0'];
	for(int i = 9;i >= 0;i--) for(int j = 1;j <= a[i];j++) printf("%d",i);
}
