//GZ-S00397 贵州省铜仁第一中学 蒲泊廷
#include<bits/stdc++.h>
using namespace std;
int w[100000][3];
int f[1000];
int main()
{
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	int n,m,k,max=0,num=0,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i][1]>>w[i][2]>>w[i][0];
		f[w[i][1]]++;
		f[w[i][2]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]>max)
		{
			max=f[i];
			num=i;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(w[i][1]==num || w[i][2]==num)
			ans+=w[i][0];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
