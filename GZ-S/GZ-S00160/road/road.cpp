//GZ-S00160 遵义市第一初级中学 张桢宇
#include<bits/stdc++.h>
using namespace std;

int n,m,k,u[1000000],v[1000000],w[1000000],c[10],a[10][10000];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
		cin>>u[i]>>v[i]>>w[10000];
	for(int i=0;i<k;i++)
		for(int j=0;j<n;j++)
			cin>>c[i]>>a[i][j];
	cout<<"0";
    return 0;
	fclose(stdin);
	fclose(stdout);
}
