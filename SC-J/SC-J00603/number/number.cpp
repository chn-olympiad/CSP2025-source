#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=205;
int n,m,tong[M];
char s[N];
bool check(char x){
	if(x>='0'&&x<='9')
		return true;
	return x>='a'&&x<='z';
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	while(check(s[n+1]))++n;
	for(int i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9')
			tong[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(tong[i]--)
			printf("%d",i);
	putchar('\n');
	return 0;
}