#include<iostream>
using namespace std;
void skp(int x,int y)
{
	int q;
	q=x;
	x=y;
	y=q;
	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,z,a[100][100];
	int b[1000];

	cin>>n>>m>>z;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			if(a[i][3]>=a[j][3])
			{
				skp(a[i][3],a[j][3]);
				skp(a[i][2],a[j][2]);
				skp(a[i][1],a[j][1]);
				
			}
		}
	}
	int s;
	for(int i=1;i<=m;i++)
	{
		for(int k=1;k<=2;k++)
		{
			int wb=a[i][k];
			int ws=a[i][2];
			int wd=a[i][1];
			if(b[wb]==0)
			{
				s+=a[i][3];
				b[ws]=1;
				b[wd]=1;
			}
		}
    }
    cout<<s;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
