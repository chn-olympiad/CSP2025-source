#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
	int a[100001],a1[100001],a2[100001],n,b[100001],b1,b2,b3,z,ans=0;
		cin>>n;
		z=n/2;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j]>>a1[j]>>a2[j];
			b[j]=a[j]-(a1[j]+a2[j]);
			b3=min(b[j],b3);
		}
		b1=b3;
     for(int x=1;x<=z;x++)
     {
     	for(int y=1;y<=n;y++)
     	{	
     	if(b[y]>b1)
     	{
     		b1=b[y];
     		b2=y;
		}
	}
	ans+=a[b2];
	a[b2]=0;
	a1[b2]=0;
	a2[b2]=0;
	b[b2]=b3;
	b1=b3;
	 }
for(int c=1;c<=n;c++)
{
	ans+=max(a1[c],a2[c]);
}	
cout<<ans<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
