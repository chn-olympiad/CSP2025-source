#include<bits/stdc++.h>
using namespace std;
long long n,c[1000010],j;
char s[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	n=strlen(s);
	for(long long i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			c[j]=s[i]-'0';
			j++;
		}
	}
	sort(c,c+j);
	for(long long k=j-1;k>=0;k--) printf("%lld",c[k]);
	return 0;
} 
