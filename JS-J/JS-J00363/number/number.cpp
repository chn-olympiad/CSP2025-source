#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005];
int main(){
	scanf("%s",s+1);
	int t=strlen(s+1);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int u=0;
	for(int i=1;i<=t;i++){
		if(s[i]>='0'&&s[i]<='9')
			a[++u]=s[i]-'0';
	}
	sort(a+1,a+u+1);
	for(int i=u;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
}
