#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int n,a[MAXN],m;
char s[MAXN];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<=n;i++) if(s[i]>='0'&&s[i]<='9') a[++m]=s[i]-'0';
	sort(a+1,a+1+m,cmp);
	if(!a[1]){
		putchar('0');
		return 0;
	}
	for(int i=1;i<=m;i++) printf("%d",a[i]);
	return 0;
} 

