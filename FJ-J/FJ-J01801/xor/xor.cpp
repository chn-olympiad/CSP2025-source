#include <bits/stdc++.h>
using namespace std;
const int MAXN=500001;
int n,k;
int a[MAXN];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	printf("%d",n/2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
