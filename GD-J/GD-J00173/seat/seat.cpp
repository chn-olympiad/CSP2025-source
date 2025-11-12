#include<bits/stdc++.h>
using namespace std;
int s[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int sum=n*m;
	for(int i=1;i<=sum;i++)scanf("%d",s+i);
	int ans=1;
	for(int i=2;i<=sum;i++)
	{
		if(s[i]>s[1])ans++;
	}
	int l=ceil(ans*1.0/n);
	ans=(ans-1)%n+1;
	int c=(l%2?ans:n+1-ans);
	printf("%d %d",l,c);
	return 0;
}
