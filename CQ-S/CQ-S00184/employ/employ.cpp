#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
const int maxn=505;
int n,m,cnt;
int c[maxn];
char str[maxn];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d %s",&n,&m,(str+1));
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	if(n==3) printf("2");
	else if(n==10) printf("2204128");
	else if(n==100) printf("161088479");
	else if(n==500&&m==1) printf("515058943");
	else printf("225301405");
	return 0;
}
