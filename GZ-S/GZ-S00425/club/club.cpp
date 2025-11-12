//GZ-S00425 赵懿 遵义市播州区新蓝学校
#include<bits/stdc++.h>
using namespace std;
int t,n[5],i1[5][10000],i2[5][10000],i3[5][10000],bu[5][3],sum[5];
void compare(int a)
{
	for(int b=1;b<=n[a];b++)
	{
		int max=0;
		if(max<i1[a][b] && (bu[a][1]+1)<=n[a]/2)
		{
			max=i1[a][b];
		}
		if(max<i2[a][b] && (bu[a][2]+1)<=n[a]/2)
		{
			max=i2[a][b];
		}
		if(max<i3[a][b] && (bu[a][3]+1)<=n[a]/2)
		{
			max=i3[a][b];
		}
		if(max==i1[a][b])
		{
			bu[a][1]++;
		}
		if(max==i2[a][b])
		{
			bu[a][2]++;
		}
		if(max==i3[a][b])
		{
			bu[a][3]++;
		}
		sum[a]=sum[a]+max;
	}
	if(a<=t)
	{
		compare(a+1);
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int a=1;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i];
		for(int j=1;j<=n[i];j++)
		{
			cin>>i1[i][j]>>i2[i][j]>>i3[i][j];
		}
	}
	compare(a);
	for(int k=1;k<=t;k++)
	{
		cout<<sum[k]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
