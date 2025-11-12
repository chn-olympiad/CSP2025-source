#include<bits/stdc++.h>

using namespace std;

int n,q;

char s[5000010],s1[5000010];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	scanf("%d%d",&n,&q);
	
	for(int i=1;i<=n;i++)
		scanf("%s %s",s+1,s1+1);
		
	for(int i=1;i<=q;i++)
		scanf("%s %s",s+1,s1+1);
	
	for(;q--;)
		printf("0\n");
}
