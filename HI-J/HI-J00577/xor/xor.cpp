#include<bits/stdc++.h>
using namespace std;
int a[500001],n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	printf("%d",a[1]);
	return 0;
}

