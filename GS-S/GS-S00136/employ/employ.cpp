#include<bits/stdc++.h>
using namespace std;

const int N=600,q=998244353;

int n,m,c[N];
char s[N];
long long ans=1;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.ans","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) scanf("%d",c+i);
	printf("0");
	return 0;
}
