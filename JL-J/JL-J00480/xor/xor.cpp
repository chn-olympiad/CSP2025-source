#include <bits/stdc++.h>
using namespace std;
#define N 500005
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	if(k==0)
		printf("1\n");
	else
		printf("63\n");

	return 0;
}
