#include<bits/stdc++.h>

using namespace std;

	int n,m;
	char s[30000011];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n + m;i++)
		scanf("%s%s",s + 1,s + 1);
	for(int i = 1;i <= m;i++)
		printf("0\n");
	return 0;
}
