//GZ-S00415 贵阳市第二实验中学 谢竞潼 
#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
long int n;
int f;
int a[100000][4];
int b[100000];
int d[4][100000];
int manyi(int t)
{
	int m=0;
	int c[4];
	int max=0;
	int h=0;
	for(int z=0;z<n;z++)
	{
		for(int s=1;s<=3;s++)
		{
			if(a[z][s]>max)
			{
				max=a[z][s];
				b[z]=s;
			}
			if(c[s]<=n/2)
			{
				c[s]=c[s]+1;
			}
		}	
		m=m+max;
		max=0;
	}
	return m;
}
int main(int argc, char** argv) {
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	for(int x=0;x<t;x++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		f=manyi(t);
	}
	cout<<f<<endl;
	return 0;
	fclose(stdin);
    fclose(stdout);
}
