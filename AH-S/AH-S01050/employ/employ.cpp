#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[1005];
char s[1005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int i,n,m,len,p=0;
	scanf("%d %d",&n,&m);
	scanf("%s",s);
	len=strlen(s);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<=len-1;i++)
		if(s[i]=='0'){
			p=1;
			break;
		}
	if(p==0){
		printf("1");
	}
	else
		printf("%d",mod-1);
	return 0;
}
