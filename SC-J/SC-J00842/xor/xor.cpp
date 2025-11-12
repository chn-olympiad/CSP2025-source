#include<bits/stdc++.h>
using namespace std;

const int MAXN=139;
int n,k;
int a[MAXN];
int eins=0,null=0;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);if(a[i]) eins++;else null++;}
	if(k) printf("%d\n",eins);
	else{
		printf("%d\n",eins/2+null);
	}
	return 0;
}