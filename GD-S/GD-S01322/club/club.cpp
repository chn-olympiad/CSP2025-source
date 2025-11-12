#include<iostream>
#include<cstdio> 
using namespace std;
long long b[4]={},dd[10005]={},f[5005][4]={},a[10005][4]={},jl[11]={};
long long ans=0;
int n,t;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
		cin>>t;
		for(int l=0;l<t;l++)
		{
			cin>>n;
			for(int i=1;i<=n;i++)
				cin>>a[i][1]>>a[i][2]>>a[i][3];	
			for(int i=1;i<=n;i++)
			{
				for(int j=(n/2);j>=1;j--)
					for(int k=1;k<=3;k++)
					{
						f[j][k]=max(f[j][k],max(f[j-1][1]+a[i][k],max(f[j-1][2]+a[i][k],f[j-1][3]+a[i][k])));
						}	
			}	
			cout<<max(f[n/2][1],max(f[n/2][2],f[n/2][3]))<<endl;
			for(int i=1;i<=n;i++)
				for(int j=n;j>=1;j--)
					for(int k=1;k<=3;k++)
						f[j][k]=0;
		}
				
	fclose(stdin);
	fclose(stdout);
	return 0;
}
