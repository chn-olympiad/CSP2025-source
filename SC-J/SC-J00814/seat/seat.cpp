#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[105]={};

bool cmp(int q,int p)
{
	return q>p;
}

signed int main(void)
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	int s=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,t=1,r=1;
	while(a[t]!=s)
	{
		if(y+r>n or y+r<1)
		{
			x++;
			r=r*(-1);
		}
		else
			y+=r;
		t++;
	}
	printf("%d %d",x,y);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}