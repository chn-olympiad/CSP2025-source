#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010],cnt=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int lens=strlen(s+1);
	for(int i=1;i<=lens;i++){
		if(s[i]>='0'&&s[i]<='9')
		{
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a+1,a+cnt);
	for(int i=cnt-1;i>=1;i--){
		printf("%d",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
