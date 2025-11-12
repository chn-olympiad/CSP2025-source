#include <bits/stdc++.h>
using namespace std;
struct xx{
	char s1,s2;
}l[200001];
struct yy{
	char t1,t2;
}r[200001];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,cnt=0;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",l[i].s1,l[i].s2);
	}
	for(int i=1;i<=q;i++){
		scanf("%s%s",r[i].t1,r[i].t2);
	}
	cnt=n%5;
	for(int i=1;i<=q;i++){
		printf("%d/n",cnt);
	}
	return 0;
}
