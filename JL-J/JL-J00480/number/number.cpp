#include <bits/stdc++.h>
using namespace std;
#define N 1000005
char s[N];
long long ans[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	long long len=strlen(s);
	long long t=0;
	for(int i=9;i>=0;i--){
		for(long long j=0;j<len;j++){
			if(s[j]-'0'==i){
				ans[t]=i;
				t++;
			}
		}
	}
	for(int i=0;i<t;i++)
		printf("%lld",ans[i]);
	printf("\n");

	return 0;
}
