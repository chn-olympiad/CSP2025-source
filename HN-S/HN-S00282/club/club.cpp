#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001],c[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,j=1,ans=0,sum=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			cin>>b[i];
			cin>>c[i];
		}	
		for(int g=1;g<=n;g++)
			for(int k=g+1;k<=n;k++)
			{
				if(a[g],a[k])
				{
					swap(a[g],a[k]);
					swap(b[g],b[k]);
					swap(c[g],c[k]);
				}
				if(a[g]==a[k])
				{
					if(b[g]<b[k])
					{
						swap(b[g],b[k]);
						swap(c[g],c[k]);
					}
					if(b[g]==b[k])
						swap(c[g],c[k]);
				}
			}
		for(int h=1;h<=n;h++)
		{
			for(int s=1;s<=n;s++)
				if(a[s]<b[s])
				{
					int temp=b[s];
					b[s]=a[s];
					a[s]=temp;
					sum++;
				}
			int maxx=max(max(a[h],b[h]),c[h]);
			a[h]=maxx;
			b[h]=0;
			c[h]=0;
		}
		j=1;
		ans=0;
		while(j<=(n/2))
		{
			ans=ans+a[j];
			j++;
			sum--;
		}
		if(sum>0)
		{
			while(j<=n)
			{
				ans=ans+b[j];
				j++;
			}
			cout<<ans<<endl;
		}
		else
		{
			while(j<=n)
			{
				ans=ans+a[j];
				j++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
