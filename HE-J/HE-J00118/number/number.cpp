#include<bits/stdc++.h>
using namespace std;

char s[10000000];

int m[20];
 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		int o=s[i]-'0';
		if(o>=0 && o<=9)
			m[o]++;
	}
//	for(int i=1;i<=9;i++)
//		printf("%d ",m[i]);
	for(int i=9;i>=0;i--)
		for(int j=1;j<=m[i];j++)
			printf("%d",i);
		
	
	
	
	
	return 0;
}
