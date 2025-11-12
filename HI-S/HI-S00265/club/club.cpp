#include<bits/stdc++.h>
using namespace std;
int T;
void solve()
{
	int n;
	cin>>n;
	int a[n+1][4];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	int b[n+1][4];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			b[i][j]=j;
		}
	}
	for(int i=1;i<=n;i++)
	{
		
		for(int j=1;j<=3;j++)
		{
			int temp;
			if(a[i][1]<a[i][2])
			{
				temp=a[i][1];
				a[i][1]=a[i][2];
				a[i][2]=temp;
				temp=b[i][1];
				b[i][1]=b[i][2];
				b[i][2]=temp; 
			}
			if(a[i][2]<a[i][3])
			{
				temp=a[i][2];
				a[i][2]=a[i][3];
				a[i][3]=temp;
				temp=b[i][2];
				b[i][2]=b[i][3];
				b[i][3]=temp;
			}
			if(a[i][1]<a[i][2])
			{
				temp=a[i][1];
				a[i][1]=a[i][2];
				a[i][2]=temp;
				temp=b[i][1];
				b[i][1]=b[i][2];
				b[i][2]=temp; 
			}
			if(a[i][2]<a[i][3])
			{
				temp=a[i][2];
				a[i][2]=a[i][3];
				a[i][3]=temp;
				temp=b[i][2];
				b[i][2]=b[i][3];
				b[i][3]=temp;
			}
		}
	}
	/*(for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
		for(int j=1;j<=3;j++)
		{
			cout<<b[i][j]<<' ';
		}
		cout<<endl;
	}*/
	for(int i=1;i<=n;i++)
	{
		a[i][0]=a[i][1]-a[i][2];
	}
	unsigned long long ans=0;
	int p[4]={0,0,0,0};
	for(int i=1;i<=n;i++)
	{
		ans+=a[i][1];
		p[b[i][1]]++;
	}
	for(int i=1;i<=3;i++)
	{
		if(p[i]>n/2)
		{
			int q[p[i]+1];
			int k=0;
			for(int j=1;j<=n;j++)
			{
				if(b[j][1]==i)
				{
					k++;
					q[k]=a[j][0];
				}
			}
			for(int j=1;j<=k;j++)
			{
				int min=q[j],minn=j;
				for(int l=j+1;l<=k;l++)
				{
					if(q[l]<min)
					{
						min=q[l];
						minn=l;
					}
				}
				int temp=q[j];
				q[j]=q[minn];
				q[minn]=temp;
			}
			for(int j=1;j<=p[i]-n/2;j++)
			{
				ans-=q[j];
			}
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		solve();
	}
	return 0;
} 
