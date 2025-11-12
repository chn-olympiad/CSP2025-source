#include<bits/stdc++.h>
using namespace std;
const int N=400;
int n,m;
int a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]); 
	int tmpa=a[1];
	sort(a+1,a+1+n*m);
	int tmp=lower_bound(a+1,a+1+n*m,tmpa)-a;
	tmp=n*m-tmp+1;
	for(int i=1;i<=m;i++)
	{
		if(i%2)
		{
			for(int j=1;j<=n;j++)
			{
				tmp--;
				if(!tmp)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				tmp--;
				if(!tmp)
				{
					printf("%d %d",i,j);
					return 0;
				}
			}
		} 
	}
		
	return 0;
}
/*
2 2
99 100 97 98

3 3
94 95 96 97 98 99 100 93 92
*/