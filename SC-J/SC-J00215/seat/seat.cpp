#include <bits/stdc++.h>

using namespace std;

const int N=20;
int a[N*N],n,m,cnt=0;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n*m;i++) if(a[i]>=a[1]) cnt++;
	int nw=0;
	for(int j=1;j<=m;j++) 
	{
		if(j%2==1) 
		{
			for(int i=1;i<=n;i++) 
			{
				nw++;
				if(nw==cnt) 
				{
					printf("%d %d",j,i);
					return 0;
				}
			}
		}
		else 
		{
			for(int i=n;i>=1;i--) 
			{
				nw++;
				if(nw==cnt) 
				{
					printf("%d %d",j,i);
					return 0;
				}
			}
		}
	}
	return 0;
} 