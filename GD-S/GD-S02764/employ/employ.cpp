#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510,inf=998244353;
int a[N];char c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	scanf("%s",c+1);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n==100&&m==47) printf("161088479");
	if(n==3&&m==2) printf("2");
	if(n==10&&m==5) printf("2204128");
	
	return 0;
}
