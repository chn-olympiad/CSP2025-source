#include<bits/stdc++.h>
using namespace std;
char s[509];
int a[509];
int N=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d", &n,&m);
	scanf("%s", s);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	long long ret=1;
	for(int i=n;i>=n-m+1;i--){
		ret=(ret%N*i)%N;
	}
	printf("%lld", ret);
	return 0;
}