#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
using namespace std;
const int N=5e5+5;
const int M=(1<<21)+5;
int n,k;
int a[N];
int pre[M];
int f[N];
int main()
{
	freopen("xor.in","r",stdin); 
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]^=a[i-1];
	f[0]=-1;
	pre[0]=n+1;
	for(int i=1;i<=n;i++) f[i]=max(f[i-1],f[pre[a[i]^k]]+1),pre[a[i]]=i;
	printf("%d",f[n]);
	return 0;
}
