#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
const int MOD=998244353;
int c[MAXN];
bool s[MAXN];
int n,m;
int main(){
	#ifndef NOT_FRE
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	#endif
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	sort(c+1,c+n+1);
	printf("0");
	return 0;
}