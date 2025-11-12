#include<bits/stdc++.h>
using namespace std;
int n,m,a[12706],xr,su,yu,ki;
bool cmp(int a,int b)
{
	return a>b; 
}
int main() 
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		if(i==1)
		{
			xr=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==xr)
		{
			su=i;
			break;
		}
	}
	ki=su/n;
	yu=su%n;
	if(yu==0)
	{
		if(ki%2==1)
		{
			cout<<ki<<" "<<n;
		 } 
		else
		{
			cout<<ki<<" "<<1;
		}
	} 
	else
	{
		if(ki%2==1)
		{
			cout<<ki+1<<" "<<n-yu+1;
		}
		else
		{
		
			cout<<ki+1<<" "<<yu;
		}
	}
	
	return 0;
}
