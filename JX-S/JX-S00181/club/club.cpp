#include<bits/stdc++.h>
using namespace std;
int t,n,m[100];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		int a1,a2,a3,b1=0,b2=0,b3=0,cz1[100010]={0},cz2[100010]={0},cz3[100010]={0};
		long long ma=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a1>>a2>>a3;
			if(a1>=a2&&a1>=a3)
			{
				ma+=a1;
				b1++;
				if(a2>=a3)
				{
					cz1[b1]=a1-a2;
				}
				else
				{
					cz1[b1]=a1-a3;
				}
			}
			else
			if(a2>=a1&&a2>=a3)
			{
				ma+=a2;
				b2++;
				if(a1>=a3)
				{
					cz2[b2]=a2-a1;
				}
				else
				{
					cz2[b2]=a2-a3;
				}
			}
			else
			if(a3>=a2&&a3>=a1)
			{
				ma+=a3;
				b3++;
				if(a2>=a1)
				{
					cz3[b3]=a3-a2;
				}
				else
				{
					cz3[b3]=a3-a1;
				}
			}
		}
		if(b1>n/2)
		{
			sort(cz1+1,cz1+1+b1);
			for(int j=1;j<=b1-n/2;j++)
			{
				ma-=cz1[j];
			}
		}
		if(b2>n/2)
		{
			sort(cz2+1,cz2+1+b2);
			for(int j=1;j<=b2-n/2;j++)
			{
				ma-=cz2[j];
			}
		}
		if(b3>n/2)
		{
			sort(cz3+1,cz3+1+b3);
			for(int j=1;j<=b3-n/2;j++)
			{
				ma-=cz3[j];
			}
		}
		m[i]=ma;
	}
	for(int i=1;i<=t;i++)
	{
		cout<<m[i]<<endl;
	}
	return 0;
}
