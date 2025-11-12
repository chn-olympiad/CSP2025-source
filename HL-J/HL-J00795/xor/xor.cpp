#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d", &n,&k);
	int a[n+5],flag=0;
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	if(a[n]==0) printf("1");
	else printf("0");
	return 0;
}
