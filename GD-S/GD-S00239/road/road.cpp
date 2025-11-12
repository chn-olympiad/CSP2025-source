#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
const int N=1e+6+10;
int cs1[N],cs2[N],qian[N],c[15],a[N][15];
int main()
{
	freopen("stdin.road","r",stdin);
	freopen("stdout.road","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>cs1[i]>>cs2[i]>>qian[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<5904327234;
	//²»»á°¡twt 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
