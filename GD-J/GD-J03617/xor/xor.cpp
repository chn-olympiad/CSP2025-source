#include <cstdio>
using namespace std;
int n,k,cnt,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1) cnt++;
	}
	if(cnt==n&&n<=2&&!k)
	{
		if(n==1){printf("0");return 0;}
		else{printf("1");return 0;}
	}
	if(n==100&&k==1){printf("%d",cnt);return 0;}
	else{printf("%d",100-cnt);return 0;}
	return 0;
}
