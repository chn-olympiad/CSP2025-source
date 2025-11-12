#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 10;

int n,len,a[N];
char s[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++){
		if (isdigit(s[i])) a[++len]=s[i]-'0';
	}
	sort(a+1,a+len+1);
	reverse(a+1,a+len+1);
	for (int i=1;i<=len;i++){
		cout << a[i];
	}
} 

