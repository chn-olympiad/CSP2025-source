#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int a[N],tot;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if('0'<=s[i]&&s[i]<='9')a[++tot]=s[i]-'0';
	}
	sort(a+1,a+tot+1);
	for(int i=tot;i;i--)printf("%d",a[i]);
	puts("");
	return 0;
}