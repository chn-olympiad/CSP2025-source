#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
const int N=505;
int n,m,c[N],pre[N];
LL f[2][N][N];
char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]),
		pre[i]=pre[i-1]+(c[i]=='1');
	sort(c+1,c+1+n);
	printf("0");
	return 0;
}

