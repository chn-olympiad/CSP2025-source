#include<bits/stdc++.h>

using namespace std;

char s[1000010];
int a[110];
char ans[1000010],top=0;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	scanf("%s",s+1);
	
	int l=strlen(s+1);
	
	for(int i=0;i<=100;i++)
		a[i]=0;
	
	for(int i=1;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;	
		}
	}
	
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=1;j<=a[i];j++)
				ans[++top]=i+'0';
		}
	}
	
	for(int i=1;i<=top;i++)
		printf("%c",ans[i]);
}
