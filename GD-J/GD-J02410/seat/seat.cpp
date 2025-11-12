#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],k,seat[15][15];
bool cmp(int l,int w)
{
	return l>w;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
		k=a[1];
	}
	sort(a+1,a+1+n*m,cmp);
	int i=1,j=1,t=1;
	while(t<=n*m)
	{
		seat[i][j]=a[t];
		if(a[t]==k)
		{
			printf("%d %d",j,i);
			return 0;
		}
		if((i==n&&j%2==1)||(i==1&&j%2==0))
		{
			j++;
		}
		else
		{
			if(j%2==1)
			{
				i++;
			}
			else
			{
				i--;
			}
		}
		t++;
	}
	return 0;
}
