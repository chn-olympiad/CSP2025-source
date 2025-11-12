#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int a1,a2,a3,index;	
};
bool cmp1(node a,node b)
{
	return a.a1>b.a1;
}
bool cmp2(node a,node b)
{
	return a.a2>b.a2;
}
bool cmp3(node a,node b)
{
	return a.a3>b.a3;
}
bool use[100001];
node a[100001],b[100001],c[100001];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while (t--)
	{
		int sum=0,sum1=0,sum2=0,sum3=0;
		cin>>n;
		for (int i=1;i<=n;i++)
			cin>>a[i].a1>>a[i].a2>>a[i].a3,a[i].index=i,b[i]=c[i]=a[i],use[i]=0;
		sort(a+1,a+1+n,cmp1);
		sort(b+1,b+1+n,cmp2);
		sort(c+1,c+1+n,cmp3);
		for (int i=1;i<=n&&sum1<n/2;i++)
			if (a[i].a1>a[i].a2&&a[i].a1>a[i].a3&&use[a[i].index]==0)
				sum+=a[i].a1,sum1++,use[a[i].index]=1;
		for (int i=1;i<=n&&sum2<n/2;i++)
			if (b[i].a2>b[i].a1&&b[i].a2>b[i].a3&&use[b[i].index]==0)
				sum+=b[i].a2,sum2++,use[b[i].index]=1;	
		for (int i=1;i<=n&&sum3<n/2;i++)
			if (c[i].a3>c[i].a1&&c[i].a3>c[i].a2&&use[c[i].index]==0)
				sum+=c[i].a3,sum3++,use[c[i].index]=1;
		for (int i=1;i<=n;i++)
			{
			if (use[a[i].index]==0)
				{
				if (sum1<n/2&&sum2>=n/2&&sum3>=n/2)sum1++,sum+=a[i].a1;
				else if (sum2<n/2&&sum1>=n/2&&sum3>=n/2)sum2++,sum+=a[i].a2;
				else if (sum3<n/2&&sum1>=n/2&&sum2>=n/2)sum3++,sum+=a[i].a3;
				else if (sum1<n/2&&sum2<n/2&&sum3>=n/2)
						{
						if (a[i].a1>a[i].a2)sum+=a[i].a1,sum1++;
						else if (a[i].a1<a[i].a2)sum+=a[i].a2,sum2++;
						else 
							{
							if (sum1<sum2)sum+=a[i].a1,sum1++;
							else sum+=a[i].a2,sum2++;
							}
						}
				else if (sum2<n/2&&sum3<n/2&&sum1>=n/2)
						{
						if (a[i].a3>a[i].a2)sum+=a[i].a3,sum3++;
						else if (a[i].a3<a[i].a2)sum+=a[i].a2,sum2++;
						else 
							{
							if (sum3<sum2)sum+=a[i].a3,sum3++;
							else sum+=a[i].a2,sum2++;
							}
						}
				else if (sum1<n/2&&sum3<n/2&&sum2>=n/2)
						{
						if (a[i].a3>a[i].a1)sum+=a[i].a3,sum3++;
						else if (a[i].a3<a[i].a1)sum+=a[i].a1,sum1++;
						else 
							{
							if (sum3<sum1)sum+=a[i].a3,sum3++;
							else sum+=a[i].a1,sum1++;
							}
						}
				else if (sum1<n/2&&sum3<n/2&&sum2<n/2)
						{
						if (a[i].a1>a[i].a2&&a[i].a1>a[i].a3)sum+=a[i].a1,sum1++;
						else if (a[i].a3>a[i].a2&&a[i].a3>a[i].a1)sum+=a[i].a3,sum3++;
						else if (a[i].a2>a[i].a1&&a[i].a2>a[i].a1)sum+=a[i].a2,sum2++;
						else
							{
							if (a[i].a1==a[i].a2)
								{
								if (sum1<sum2)sum1++,sum+=a[i].a1;
								else sum+=a[i].a2,sum2++;
								}
							else if (a[i].a2==a[i].a3)
									{
									if (sum3<sum2)sum3++,sum+=a[i].a3;
									else sum+=a[i].a2,sum2++;
									}
							else if (a[i].a1==a[i].a3)
									{
									if (sum3<sum1)sum3++,sum+=a[i].a3;
									else sum+=a[i].a1,sum1++;
									}
							else 
								{
								if (sum1>sum2&&sum1>sum3)sum1++,sum+=a[i].a1;
								else if(sum2>sum3&&sum2>sum1)sum2++,sum+=a[i].a2;
								else if (sum3>sum2&&sum3>sum1)sum3++,sum+=a[i].a3;
								else sum1++,sum+=a[i].a1;
								}
							}
						}
				}
			}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
