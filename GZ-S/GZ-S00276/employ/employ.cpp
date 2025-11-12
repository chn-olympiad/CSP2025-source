//GZ-S00276 贵阳中天中学 杨雨辰
#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s;
	int n,m;
	long long sum=1;
	scanf("%d%d",&n,&m);
	scanf("%s",&s);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		sum=(sum*i)%998244353;
	}
	printf("%lld",sum);
	fclose(stdin);
    fclose(stdout);
}
