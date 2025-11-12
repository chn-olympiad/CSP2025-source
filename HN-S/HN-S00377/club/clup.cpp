#include <bits/stdc++.h>
using namespace std;
int main() {
	int a,n[5],z[5][100001][3];
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(int i=1;i<=a;i++)
	{
		int d=0,f=0;
		for(int j=0;j<=n[i]-1;j++)
		{
			for(int l=0;l<=2;l++) 
			{
				if(z[i][j][l]>d) d=z[i][j][l];
			}
			f+=d;
		}
		cout<<f<<endl;
	}
	return 0;
}
