#include<bits/stdc++.h>
using namespace std;

#define Fre(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);

const int N=1e6+10;

int n,m;
char s[N];
int a[N];

int main(){
	Fre("number");
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)
		if(s[i]>='0'&&s[i]<='9')
			a[++m]=s[i]-'0';
	sort(a+1,a+m+1,[](int a,int b){return a>b;});
	for(int i=1;i<=m;++i) printf("%d",a[i]);puts("");
	
	return 0;
}