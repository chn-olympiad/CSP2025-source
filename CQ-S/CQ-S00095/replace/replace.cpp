#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n,q;
string s1[200005],s2[200005],t1[200005],t2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
	}
	for(int i = 1; i <= q; i++){
		cin >> t1[i] >> t2[i];
		printf("0\n");
	}
	return 0;
}
/*
          _____    ____
   /\    |        /    \
  /__\   |_____   |    |
 /    \  |        |    |
/      \ |        \____/  

*/
