#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[100010]={},b[100010]={},c[100010]={},d[100010]={},cmax[100010]={};

bool cmp(int a,int b)
{
	if(a>b) return true;
	else return false;
}
int main()
{
 	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;  
	cin>>t;
	long long sum=0;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			sum=0;
			cin>>a[i]>>b[i]>>c[i];
			long long middle=max(a[i],b[i]);
			d[i]=max(middle,c[i]);
			long long o=min(a[i],b[i]);
			long long k=min(k,c[i]);
			if(a[i]!=d[i] && a[i]!=k)
			{
				cmax[i]=a[i];
			}
			if(b[i]!=d[i] && b[i]!=k)
			{
				cmax[i]=b[i];
			}
			if(c[i]!=d[i] && c[i]!=k)
			{
				cmax[i]=c[i];
			}
			if(a[i]==b[i] && b[i]==c[i])
			{
				d[i]=a[i];
				cmax[i]=a[i];
			}
		}
		if(n==1)
		{
			cout<<d[1];
		}
		if(n==2)
		{
			int ans,p;
			if(d[1]==a[1]) ans=1;
			if(d[1]==b[1]) ans=2;
			if(d[1]==c[1]) ans=3;
			if(d[2]==a[2]) p=1;
			if(d[2]==b[2]) p=2;
			if(d[2]==c[2]) p=3;
				if(d[1]>d[2] && ans==p)
				{
					sum+=d[1];
					sum+=cmax[2];
				}
				else if(d[2]>d[1] && ans==p)
				{
					sum+=d[2];
					sum+=cmax[1];
				}
				else if(d[1]>d[2] && ans!=p)
				{
					sum+=d[1];
					sum+=d[2];
				}
				else if(d[2]>d[1] && ans!=p)
				{
					sum+=d[2];
					sum+=d[1];
				}
				else if(d[1]==d[2] && ans==p)
				{
					
					if(cmax[1]>cmax[2])
					{
						sum+=d[2];
						sum+=cmax[1];
					}
					else if(cmax[2]>cmax[1]){
						sum+=d[1];
						sum+=cmax[2];
					}
					else
					{
						sum+=d[1];
						sum+=cmax[2];
					}
				}
				else
				{
					sum=d[1]+d[2];
				}
		    cout<<sum;
		}
		else{
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++)
			{
				sum+=a[i];
			}
			cout<<sum;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
