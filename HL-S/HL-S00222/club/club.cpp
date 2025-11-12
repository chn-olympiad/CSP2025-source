#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][10],b0,b1,b2,c,m = 0,ec,minb,minz;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t)
	{
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a[i][0]);scanf("%d",&a[i][1]);scanf("%d",&a[i][2]);
			a[i][7] = a[i][0];
			a[i][8] = a[i][1];
			a[i][9] = a[i][2];
			if(a[i][0] >= a[i][1] && a[i][0] >= a[i][2])
			{
				a[i][3] = 0;
				b0++;
				m += a[i][0];
				a[i][4] = a[i][0];
				a[i][5] = max(a[i][1],a[i][2]);
				a[i][6] = min(a[i][1],a[i][2]);
				a[i][1] = -1;
				a[i][2] = -1;
				
			}
			else if(a[i][1] >= a[i][0] && a[i][1] >= a[i][2])
			{
				a[i][3] = 1;
				b1++;
				m += a[i][1];
				a[i][4] = a[i][1];
				a[i][5] = max(a[i][0],a[i][2]);
				a[i][6] = min(a[i][0],a[i][2]);
				a[i][0] = -1;
				a[i][2] = -1;
			}
			else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][0])
			{
				a[i][3] = 2;
				b2++;
				m += a[i][2];
				a[i][4] = a[i][2];
				a[i][5] = max(a[i][0],a[i][1]);
				a[i][6] = min(a[i][0],a[i][1]);
				a[i][0] = -1;
				a[i][1] = -1;
			}
		}
		if(b0 > n / 2)
		{
			c = b0 - n/2;
			for(int i = 0;i < c;i++)
			{
				for(int j = 0;j < n - 1;j++)
				{
					if(a[j][0] != -1 && a[j][0] < minb)
					{
						minb = a[j][0];
						minz = j;
					}
				}
				m -= minb;
				m += a[minz][5];
			
			}
		}
		if(b1 > n / 2)
		{
			c = b1 - n/2;
			for(int i = 0;i < c;i++)
			{
				for(int j = 0;j < n - 1;j++)
				{
					if(a[j][1] != -1 && a[j][1] < minb)
					{
						minb = a[j][1];
						minz = j;
					}
				}
				m -= minb;
				m += a[minz][5];
			
			}
		}
		if(b2 > n / 2)
		{
			c = b2 - n/2;
			for(int i = 0;i < c;i++)
			{
				for(int j = 0;j < n - 1;j++)
				{
					if(a[j][2] != -1 && a[j][2] < minb)
					{
						minb = a[j][2];
						minz = j;
					}
				}
				m -= minb;
				m += a[minz][5];
			
			}
		}
		printf("%d",m);
		t--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}