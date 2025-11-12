#include<bits/stdc++.h>
using namespace std;
int n,m,ans,ans1;
int x1[109];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&x1[i]);
	ans=x1[1];
	sort(x1+1,x1+n*m+1);
	for(int i=1;i<=n*m;i++)if(x1[i]==ans)ans1=n*m-i+1;
	int a=ans1/n,b=ans1%n;
	if(b!=0)a++;
	else b=n;
	printf("%d ",a);
	if(a%2==0)printf("%d",n-b+1);
	else printf("%d",b);
	return 0;
}

