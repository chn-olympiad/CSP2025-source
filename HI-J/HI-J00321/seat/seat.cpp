#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int c[20][20];
	int f[200],px[200];
	int mm=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		
		scanf("%d",&f[i]);
		
	}
	mm=f[1];
	if(n==1&&m==1)
	{
		printf("1 1");
	}
	else
	{
		sort(f+1,f+n*m+1);
		int o=0;

		for(int i=m*n;i>=1;i--)
		{
			o++;
			px[o]=f[i];
		}
		o=0; 
		for(int j=1;j<=m;j++)
		{
		
			if(j%2!=0)//奇数列 从上往下 
			{
				
				for(int i=1;i<=n;i++)
				{
					o++;
					c[i][j]=px[o];
				}
			} 
			if(j%2==0)//偶数列 从下往上 
			{
			
				for(int i=n;i>=1;i--)
				{
					o++;
					c[i][j]=px[o];
				}
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(c[i][j]==mm)
				{
					printf("%d %d",j,i);
					break;
				}
			}
			
		}
	}
	return 0;
}

