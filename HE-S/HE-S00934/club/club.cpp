#include<bits/stdc++.h>
using namespace std;
int t,p[100005],b[4];
struct stu{
	int sl;
	int st;
}a[100005][3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int n,c;
	while(t--)
	{
		cin>>n;
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j].sl;
				a[i][j].st=j;
				if(a[i][j].sl>=p[i])
				{
					p[i]=max(p[i],a[i][j].sl);
					c=j;
				}
			}
			b[c]++;			
		}
		for(int i=1;i<=n-1;i++)
		{
			if(b[1]>n/2)
			{
				if(p[i]<a[i][2].sl+a[i+1][1].sl)
				{
					p[i]=max(a[i][3].sl,a[i][2].sl);
				}
			}
			if(b[2]>n/2)
			{
				if(p[i]<a[i][1].sl+a[i+1][2].sl)
				{
					p[i]=max(a[i][1].sl,a[i][3].sl);
				}
			}
			if(b[3]>n/2)
			{
				if(p[i]<a[i][2].sl+a[i+1][3].sl)
				{
					p[i]=max(a[i][1].sl,a[i][2].sl);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			sum+=p[i];
		}
		cout<<sum<<endl;			
	}
	return 0;
}
