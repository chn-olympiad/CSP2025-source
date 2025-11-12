#include<bits/stdc++.h>
using namespace std;
int n,m;
char s;
unsigned long long sum,ans;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin >> s;
		if(s=='1')
			sum+=1;
	}
	ans=1;
	for(unsigned long long i=1;i<=sum;i++)
		ans*=i;
	printf("%lld",ans);
	return 0;
}
