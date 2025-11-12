#include<cstdio>
#include<cstring>
using namespace std;
int n,ans[10],l;
char c[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c);
	l=strlen(c);
	for(int i=0;i<l;++i) 
		if(c[i]>='0'&&c[i]<='9') ans[c[i]-48]++;
	for(int i=9;i>=0;--i) 
		while(ans[i]) printf("%d",i),ans[i]--;
	return 0;
}
