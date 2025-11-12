#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r;
bool cmp(int a,int b)
{
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			int h=(i-1)/n+1,d=(i-1)%n+1;
			if(h%2==1)
			{
				printf("%d %d",h,d);
			}
			else
			{
				printf("%d %d",h,n-d+1);
			}
			break;
		}
	}
	
	return 0;
}
