#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		int ans=0;
		int a1[n+1],a2[n+1],a3[n+1];
		for(int j=1;j<=n;j++)
		{
			cin>>a1[j]>>a2[j]>>a3[j];
			if(a1[j]<a2[j])
			{
				int jz=a1[j];
				a1[j]=a2[j];
				a2[j]=jz;
			}
			if(a1[j]<a3[j])
			{
				int jz=a1[j];
				a1[j]=a3[j];
				a3[j]=jz;
			}
			if(a2[j]<a3[j])
			{
				int jz=a2[j];
				a2[j]=a3[j];
				a3[j]=jz;
			}
		}
		for(int k=1;k<=n;k++)
		{
			ans=ans+a1[k];
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
