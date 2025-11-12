#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,m,a[1000],s,ct,q;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		ct++;
		if(a[i]==s) 
		{
			break;	
		}
	}
	if(ct%n==0) printf("%d ",ct/n);
	else printf("%d ",ct/n+1);
	if(ct%(2*n)==0) q=2*n;
	else q=ct%(2*n);
	if(q>n) printf("%d",n*2-q+1);
	else printf("%d",q);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
