#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100, mod=998244353;
int n, m, q,a[N], b[N], op;
char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int flag=0;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		a[i]=(s[i]-'0');
		if(!a[i])flag=1;
	}
	
	for(int i=1;i<=n;i++)scanf("%d",&b[i]), op+=(b[i]==0);
	if(!flag){
		printf("%d",op);	
	}
	
	
	return 0;
} 
