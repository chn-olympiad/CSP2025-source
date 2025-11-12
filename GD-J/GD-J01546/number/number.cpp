#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,tot;
int num[N];
char s[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]>='0' && s[i]<='9')
			num[++tot]=s[i]-'0';
	}
	sort(num+1,num+n+1,cmp);
	for(int i=1;i<=tot;i++)
		printf("%d",num[i]);
	return 0;
}
