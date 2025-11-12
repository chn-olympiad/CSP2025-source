#include<iostream>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	int i,j,n,m,k,s=0;
	int a[1001][1001];
	cin>>n;
	cin>>m;
	cin>>k;
	for(i=1;i<=m;++i)
	{
		for(j=0;j<3;++j)
		  cin>>a[i][j];
	}
	for(i=1;i<=m;++i)
	{
		for(j=2;j<3;++j)
		{
			if(j==2)
			  s=s+a[i][j];
		}
	}
	cout<<s;
	return 0;
	fclose(stdin);
    fclose(stdout);
}
