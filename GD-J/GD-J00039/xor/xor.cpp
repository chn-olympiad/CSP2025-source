#include<iostream>
#include<cstdio>
using namespace std;

int n,k,a[110];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) cin>>a[i];
	printf("%d\n",n/2);
	return 0;
}
