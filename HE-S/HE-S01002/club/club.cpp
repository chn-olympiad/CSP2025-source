#include <bits/stdc++.h>
using namespace std;
int t,n,f,f0,sum,mx=-1;
int a[100005],b[100005],c[100005];
int p[100005][4];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			p[i][1]=a[i];
			p[i][2]=b[i];
			p[i][3]=c[i];
			if(b[i]!=0||c[i]!=0) f=1;
			if(c[i]!=0) f0=1;		
		}
		if(f==0)
		{
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++)
			{
				sum+=a[i];
			}
			cout<<sum;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				sum+=max(max(p[i][1],p[i][2]),p[i][3]);
			}
			cout<<sum<<endl;
		}
		sum=0;
	}
	return 0;
}
