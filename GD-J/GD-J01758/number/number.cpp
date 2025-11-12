#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,s[N],len,t[N];
char c[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c);
	n=strlen(c);
	for(int i=0;i<n;i++)
		if('0'<=c[i]&&c[i]<='9')
			t[c[i]-'0']++;
	for(int i=9;~i;i--)
		while(t[i]--) putchar(i+'0');
	return 0;
}
