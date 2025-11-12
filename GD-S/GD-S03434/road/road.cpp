#include <bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005],c[1000005],chun[5][40004];
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	bool flag=false;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>chun[i][j];
			if(chun[i][j]==0) flag=true;
		} 
	}
	if(flag==true) cout<<0;
	else
	{
		sort(c+1,c+m+1,cmp);
		int num=0;
		for(int i=1;i<=m-1;i++)
		{
			
			num+=c[i];
		}
		
		cout<<num;
	}
	return 0;
}
