#include<bits/stdc++.h>
using namespace std;
FILE *fin,*fout;
int n,m;
long long s,i=1,j=1,test;
int seat[15][15]={};
int main()
{
	fin=fopen("seat.in","r");
	fout=fopen("seat.out","w");
	fscanf(fin,"%d",&n);
	fscanf(fin,"%d",&m);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			fscanf(fin,"%d",&seat[i][j]);
		}
	}
	test=seat[1][1];
	int s=1,s2=1;
	for(s=1;s<=m*n;s++)
	{
	for(i=1;i<=m;i++)
		{
		for(j=1;j<=n;j++)
		{
			if(i%2==0)
			{
				if(j==1)
				{
					if(seat[i][j]<seat[i+1][1])
					{
						swap(seat[i][j],seat[i+1][1]);
					}
				}
				else
				{
					if(seat[i][j]<seat[i][j-1])
					{
						swap(seat[i][j],seat[i][j-1]);
					}
				}
			}
			else
			{
				if(j==n)
				{
					if(seat[i][j]<seat[i+1][n])
					{
						swap(seat[i][j],seat[i+1][n]);
					}
				}
				else
				{
					if(seat[i][j]<seat[i][j+1])
					{
						swap(seat[i][j],seat[i][j+1]);
					}
				}
			}
		}
		}
		i=1;
		j=1;
	}
		int c,r;
		for(c=1;c<=m;c++)
		{
			for(r=1;r<=n;r++)
		{
			if(seat[c][r]==test)
			{
				fprintf(fout,"%d %d",c,r);
			}
		}
		}
	fclose(fin);
	fclose(fout);
	return 0;
} 