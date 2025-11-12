#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005];
bool cmp(int s,int f)
{
	if(s>=f)return 1;
	else return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	scanf("%d",&a[i]);
	int q=a[1],u=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==q)
		{
			u=i;
			break;
		}
	}
	if(u%n==0)
	{
		printf("%d ",u/n);
		if((u/n)%2==1)printf("%d",n);
		else printf("%d",1);
	}
	else 
	{
		printf("%d ",u/n+1);
		if((u/n)%2==0)printf("%d",u%n);
		else printf("%d",n-(u%n)+1);
	}
	return 0;
} 
