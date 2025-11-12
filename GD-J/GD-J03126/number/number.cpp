#include<bits/stdc++.h>

using namespace std;
int read(){
	char ch=getchar();
	int k=0,f=1;
	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) {k=(k<<1)+(k<<3)+ch-48;ch=getchar();}
	return k*f; 
}
const int N=1e6+7;
char s[N];
int cnt,p[N];
int main(){
	freopen("number4.in","r",stdin);
	freopen("number4.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(isdigit(s[i])) p[++cnt]=s[i]-'0';
	sort(p+1,p+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++)
		printf("%d",p[i]);
	return 0;
}
