#include<bits/stdc++.h>
using namespace std;
int n,N=998244353,a[514];
long long m;
char c[514];
int main(){
	freopen("employ1.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%lld",&n,&m);
	scanf("&s",c);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	srand(time(0));
	for(int i=n;i;i--){
		m*=rand();
		m%=N;
	}
	printf("%lld",m);
	return 0;
}
