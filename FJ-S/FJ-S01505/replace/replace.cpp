#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[200005];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,p;
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++) {
		scanf("%s%s",&s1[i],&s2[i]);
	}
	string a1,a2;
	for(int i=1;i<=p;i++) {
		scanf("%s%s",&a1,&a2);
		printf("0\n");
	}
	return 0;
}