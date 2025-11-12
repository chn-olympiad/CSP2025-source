#include<bits/stdc++.h>
using namespace std;
int n,q;
char s1[100010],s2[100010],t1[200001],t2[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i = 1; i <= n; i++){
		scanf("%d%d",&s1[i],&s2[i]);
	}
	for(int j = 1; j <= q; j++){
		scanf("%d%d",&t1[j],&t2[j]);
	}
}
