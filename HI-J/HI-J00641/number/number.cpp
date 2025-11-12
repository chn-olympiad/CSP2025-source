#include<bits/stdc++.h>
using namespace std;
char s[1010011];
int a[1010100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int len=strlen(s+1);
	int cnt=0;
	for(int i=1;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9')a[++cnt]=(s[i]-'0');
	}
	sort(a+1,a+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++)printf("%d",a[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
