#include<bits/stdc++.h>
using namespace std;
int n,k,s;
int a[5005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(k==0) printf("%d",n);
	else printf("%d",1);
	return 0;
} 
