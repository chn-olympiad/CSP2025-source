#include<bits/stdc++.h>
using namespace std;
long long idea[1001][1001],t,n,duty[4],sum,maxn,maxp;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int z=0;z<t;z++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<3;j++)
				cin>>idea[i][j];
		for(int i=n-1;i>=0;i--)
		{
			for(int j=0;j<3;j++)
			{
				if(duty[j]>=n/2)
					idea[i][j]=0;
				}
			for(int k=0;k<3;k++)
				if(idea[i][k]>maxn)
				{
					maxn=idea[i][k];
					maxp=k;
				}
				sum+=maxn;
				duty[maxp]++;
				maxn=0;
				maxp=0;
		}
		cout<<sum<<endl;
		maxn=0;
		maxp=0;
		sum=0;	
		for(int k=0;k<3;k++)
		duty[k]=0;	
	}	
	return 0;
}
