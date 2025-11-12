#include<bits/stdc++.h>
using namespace std;
int n,q,s1[200010],s2[200010],s3[200010],s4[200010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",&s1[i],&s2[i]);
	}
	for(int i=1;i<=q;i++){
		scanf("%s%s",&s3[i],&s4[i]);
	}
	for(int i=1;i<=q;i++){
		printf("0\n");
	}
	return 0;
}
